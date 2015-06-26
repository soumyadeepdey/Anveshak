
#include "myheader.h"
#include "groundtruth.h"
#include "ui_groundtruth.h"
#include "continue.h"
#include "selectlabel.h"
#include "updatelabelasking.h"
#include "QMessageBox"


IITkgp_functions::RectangleTest rt;

/*****************************Give Label To ALL PB Within a ROI With a Particular Label***********************************************/


void IITkgp_functions::LabellingROI::GiveSameLabelToAllPb(Rect ROI, int label)
{
    int k = 0;
    for(int i=0;i<contours.size();i++)
    {
        if(hierarchy[i][3] == -1 && validblock[i] == true)
        {
            vector<Point> contours_poly;
            Rect BoundRect;
            approxPolyDP( Mat(contours[i]), contours_poly, 3, true );
            BoundRect = boundingRect( Mat(contours_poly) );

            if(rt.FindOverlappingRectangles(ROI,BoundRect) == 2)
            {
                //bool lo = LabelFlag[k];
                if(LabelFlag[k] == true) // if labelled
                {
                    //printf("hellofdfhgvafasf\n");
                    int temp_posi = PBLabel[k];

                    LabelCount[temp_posi] = LabelCount[temp_posi] - 1;
                    LabelCount[label] = LabelCount[label] + 1;



                    for(int m=BoundRect.y;m<BoundRect.y+BoundRect.height;m++)
                    {

                        for(int n=BoundRect.x;n<BoundRect.x+BoundRect.width;n++)
                        {
                            bool measure_dist;
                            if((pointPolygonTest(contours_poly,Point(n,m),measure_dist) > 0.0) && src_binary.data[m*src_binary.cols+n]==0)
                            {
                                LabelImages[label].data[m*ColorLabelImage.cols+n] = 0;
                                LabelImages[temp_posi].data[m*ColorLabelImage.cols+n] = 0;
                                LabelImageInOne.data[m*ColorLabelImage.cols+n] = label;
                                ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+0] = LabelColor[label][0];
                                ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+1] = LabelColor[label][1];
                                ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+2] = LabelColor[label][2];
                            }
                        }
                    }



                    PBLabel[k] = label;

                }
                else // if not labelled
                {


                    LabelFlag[k] = true;
                    PBLabel[k] = label;
                    UnlabelledPB = UnlabelledPB - 1;
                    LabelCount[label] = LabelCount[label] + 1;

                    for(int m=BoundRect.y;m<BoundRect.y+BoundRect.height;m++)
                    {

                        for(int n=BoundRect.x;n<BoundRect.x+BoundRect.width;n++)
                        {
                            bool measure_dist;
                            if((pointPolygonTest(contours_poly,Point(n,m),measure_dist) > 0.0) && src_binary.data[m*src_binary.cols+n]==0)
                            {
                                LabelImages[label].data[m*ColorLabelImage.cols+n] = 0;
                                LabelImageInOne.data[m*ColorLabelImage.cols+n] = label;
                                ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+0] = LabelColor[label][0];
                                ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+1] = LabelColor[label][1];
                                ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+2] = LabelColor[label][2];
                            }
                        }
                    }


                }
            }

            k++;
        }
    }


}

/************************Give Label To ALL Unlabelled PB Within a ROI With a Particular Label*******************************************/


void IITkgp_functions::LabellingROI::GiveSameLabelToUnlabelledPB(Rect ROI, int label)
{
    int k = 0;
    for(int i=0;i<contours.size();i++)
    {
        if(hierarchy[i][3] == -1 && validblock[i] == true)
        {
            vector<Point> contours_poly;
            Rect BoundRect;
            approxPolyDP( Mat(contours[i]), contours_poly, 3, true );
            BoundRect = boundingRect( Mat(contours_poly) );

            if(rt.FindOverlappingRectangles(ROI,BoundRect) == 2)
            {
                if(LabelFlag[k] == false) // if PBs are not labelled
                {
                    LabelFlag[k] = true;
                    PBLabel[k] = label;
                    UnlabelledPB = UnlabelledPB - 1;
                    LabelCount[label] = LabelCount[label] + 1;

                    for(int m=BoundRect.y;m<BoundRect.y+BoundRect.height;m++)
                    {

                        for(int n=BoundRect.x;n<BoundRect.x+BoundRect.width;n++)
                        {
                            bool measure_dist;
                            if((pointPolygonTest(contours_poly,Point(n,m),measure_dist) > 0.0) && src_binary.data[m*src_binary.cols+n]==0)
                            {
                                LabelImages[label].data[m*ColorLabelImage.cols+n] = 0;
                                LabelImageInOne.data[m*ColorLabelImage.cols+n] = label;
                                ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+0] = LabelColor[label][0];
                                ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+1] = LabelColor[label][1];
                                ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+2] = LabelColor[label][2];
                            }
                        }
                    }

                }
            }
            k++;
        }
    }
}


/************************Give Label To PB within ROI with Different Label*******************************************/


void IITkgp_functions::LabellingROI::GiveDiffLabelToPB(Rect ROI)
{
    SelectLabel sl;

    int k = 0;
    for(int i=0;i<contours.size();i++)
    {
        if(hierarchy[i][3] == -1 && validblock[i] == true)
        {
            vector<Point> contours_poly;
            Rect BoundRect;
            approxPolyDP( Mat(contours[i]), contours_poly, 3, true );
            BoundRect = boundingRect( Mat(contours_poly) );

            if(rt.FindOverlappingRectangles(ROI,BoundRect) == 2)
            {
                char *name;
                name = (char *) malloc(2000 * sizeof(char));
                int sp = sprintf(name,"Processing Block%d",k);
                tempname = name;
                namedWindow(name, CV_WINDOW_KEEPRATIO);
                Mat Temp;
                Temp = Blocks[k];
                imshow(name, Temp);



                if(LabelFlag[k]) // if already Labelled
                {
                    QMessageBox::information(0,"Labelling","Label of Processing block is "+Labels[k]);
                    UpdateLabelAsking ula;
                    ula.setModal(true);
                    ula.exec();
                    if(cflag)
                    {


                        sl.setModal(true);  // select Label
                        sl.exec();



                        LabelCount[PBLabel[k]] = LabelCount[PBLabel[k]] - 1;
                        LabelCount[selectedlabel] = LabelCount[selectedlabel] + 1;

                        for(int m=BoundRect.y;m<BoundRect.y+BoundRect.height;m++)
                        {

                            for(int n=BoundRect.x;n<BoundRect.x+BoundRect.width;n++)
                            {
                                bool measure_dist;
                                if((pointPolygonTest(contours_poly,Point(n,m),measure_dist) > 0.0) && src_binary.data[m*src_binary.cols+n]==0)
                                {
                                    LabelImages[selectedlabel].data[m*ColorLabelImage.cols+n] = 0;
                                    LabelImages[PBLabel[k]].data[m*ColorLabelImage.cols+n] = 0;
                                    LabelImageInOne.data[m*ColorLabelImage.cols+n] = selectedlabel;
                                    ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+0] = LabelColor[selectedlabel][0];
                                    ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+1] = LabelColor[selectedlabel][1];
                                    ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+2] = LabelColor[selectedlabel][2];
                                }
                            }
                        }

                        PBLabel[k] = selectedlabel;

                    }

                    destroyWindow(name);

                    Continue con;
                    con.setModal(true);
                    con.exec();

                    if(!cflag)
                        break;
                }
                else // If Pb is not Labelled
                {
                    sl.setModal(true);  // select Label
                    sl.exec();
                    destroyWindow(name);

                    PBLabel[k] = selectedlabel;
                    LabelFlag[k] = true;
                    UnlabelledPB = UnlabelledPB - 1;
                    LabelCount[selectedlabel] = LabelCount[selectedlabel] + 1;

                    for(int m=BoundRect.y;m<BoundRect.y+BoundRect.height;m++)
                    {

                        for(int n=BoundRect.x;n<BoundRect.x+BoundRect.width;n++)
                        {
                            bool measure_dist;
                            if((pointPolygonTest(contours_poly,Point(n,m),measure_dist) > 0.0) && src_binary.data[m*src_binary.cols+n]==0)
                            {
                                LabelImages[selectedlabel].data[m*ColorLabelImage.cols+n] = 0;
                                LabelImageInOne.data[m*ColorLabelImage.cols+n] = selectedlabel;
                                ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+0] = LabelColor[selectedlabel][0];
                                ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+1] = LabelColor[selectedlabel][1];
                                ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+2] = LabelColor[selectedlabel][2];
                            }
                        }
                    }


                }

                Temp.release();
            }

            k++;
        }
    }
}
