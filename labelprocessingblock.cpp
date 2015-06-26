#include "labelprocessingblock.h"
#include "ui_labelprocessingblock.h"
#include "myheader.h"
#include "continuelabeling.h"
#include "selectlabel.h"
#include "QMessageBox"
#include "labelroi.h"
#include "updatelabelofpb.h"
#include "chagelabelofpbs.h"
#include "continue.h"

char *tempname;



LabelProcessingBlock::LabelProcessingBlock(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LabelProcessingBlock)
{
    ui->setupUi(this);

}

LabelProcessingBlock::~LabelProcessingBlock()
{
    delete ui;
}

bool cflag;
void LabelProcessingBlock::on_pushButton_clicked() // single PB labeling
{
    //IITkgp_functions::ProcessingBlocks PB;
    //PB.LabelPB();
    cflag = false;


    int k = 0;

    for(int i=0;i<contours.size();i++)
    {
        if(hierarchy[i][3] == -1)
        {
            if(LabelFlag[k] == false)
            {
                int sp;
                char *name;
                name = (char *) malloc(2000 * sizeof(char));
                sp = sprintf(name,"Processing Block%d",i);
                tempname = name;
                namedWindow(name, CV_WINDOW_KEEPRATIO);
                Mat Temp;
                Temp = Blocks[k];
                imshow(name, Temp);

                continuelabeling cl;
                SelectLabel sl;

                sl.exec();
                //waitKey(0);
                Temp.release();
                PBLabel[k] = selectedlabel;
                LabelFlag[k] = true;
                UnlabelledPB = UnlabelledPB - 1;
                LabelCount[selectedlabel] = LabelCount[selectedlabel] + 1;

                cl.exec();
                if(cflag)
                {
                    break;
                }
                vector<Point> contours_poly;
                Rect BoundRect;
                approxPolyDP( Mat(contours[i]), contours_poly, 3, true );
                BoundRect = boundingRect( Mat(contours_poly) );

                for(int m=BoundRect.y;m<BoundRect.y+BoundRect.height;m++)
                {

                    for(int n=BoundRect.x;n<BoundRect.x+BoundRect.width;n++)
                    {
                        bool measure_dist;
                        if((pointPolygonTest(contours_poly,Point(n,m),measure_dist) > 0.0) && src_binary.data[m*src_binary.cols+n]==0)
                        {
                            if(LabelFlag[k])
                            {
                                LabelImages[selectedlabel].data[m*ColorLabelImage.cols+n] = 0;
                                ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+0] = LabelColor[selectedlabel][0];
                                ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+1] = LabelColor[selectedlabel][1];
                                ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+2] = LabelColor[selectedlabel][2];
                            }

                        }
                    }
                }
            }
            k = k + 1;

        }
    }



    if(UnlabelledPB == 0) // labelling of all PB is done
    {
        QMessageBox::information(0,"Labelling","Labelling of All Processing block are done");
        // Want to Re label

    }
    else
    {
        QMessageBox::information(0,"Labelling","Labelling of All Processing block are not done");
        LabelProcessingBlock lpb;
        lpb.setModal(true);
        lpb.exec();
        this->close();
    }

}

void LabelProcessingBlock::on_pushButton_3_clicked() // Done
{

    ChageLabelofPBs CLPB;

   // src_ub.copyTo(ColorLabelImage);

    tempname = "Labeled Blocks";
    namedWindow(tempname,CV_WINDOW_KEEPRATIO);

    if(UnlabelledPB!=0) // if all PB are not labelled
    {
        QMessageBox::information(0,"Labelling","Labelling of All Processing block are not done");
        LabelProcessingBlock lpb;

        /*
        int k = 0;

        for(int i=0;i<contours.size();i++)
        {
            if(hierarchy[i][3] == -1)
            {
                vector<Point> contours_poly;
                Rect BoundRect;
                approxPolyDP( Mat(contours[i]), contours_poly, 3, true );
                BoundRect = boundingRect( Mat(contours_poly) );

                for(int m=BoundRect.y;m<BoundRect.y+BoundRect.height;m++)
                {

                    for(int n=BoundRect.x;n<BoundRect.x+BoundRect.width;n++)
                    {
                        bool measure_dist;
                        if((pointPolygonTest(contours_poly,Point(n,m),measure_dist) > 0.0) && src_binary.data[m*src_binary.cols+n]==0)
                        {
                            if(LabelFlag[k])
                            {
                                ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+0] = LabelColor[PBLabel[k]][0];
                                ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+1] = LabelColor[PBLabel[k]][1];
                                ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+2] = LabelColor[PBLabel[k]][2];
                            }

                        }
                    }
                }
                k = k + 1;
            }
        }
*/

        imshow(tempname,ColorLabelImage);
        waitKey(0);

        lpb.setModal(true);
        lpb.exec();


        this->close();
    }
    else // if all PB are labelled
    {

        /*

        for(int i=0;i<contours.size();i++)
        {
            if(hierarchy[i][3] == -1)
            {
                vector<Point> contours_poly;
                Rect BoundRect;
                approxPolyDP( Mat(contours[j]), contours_poly, 3, true );
                BoundRect = boundingRect( Mat(contours_poly) );

                for(int m=BoundRect.y;m<BoundRect.y+BoundRect.height;m++)
                {

                    for(int n=BoundRect.x;n<BoundRect.x+BoundRect.width;n++)
                    {
                        bool measure_dist;
                        if((pointPolygonTest(contours_poly,Point(n,m),measure_dist) > 0.0) && src_binary.data[m*src_binary.cols+n]==0)
                        {
                            ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+0] = LabelColor[PBLabel[k]][0];
                            ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+1] = LabelColor[PBLabel[k]][1];
                            ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+2] = LabelColor[PBLabel[k]][2];
                        }
                    }
                }
            }
        }

        cflag = false;
        */

        imshow(tempname,ColorLabelImage);
        waitKey(0);
        this->close();
        QMessageBox::information(0,"Labelling","Labelling of All Processing block are done");
        CLPB.setModal(true);
        CLPB.exec();



    }








}



void LabelProcessingBlock::on_pushButton_2_clicked() // select ROI
{
    IITkgp_functions::ProcessingBlocks PB;
    IITkgp_functions::RectangleTest RT;
    LabelROI LR;
    UpdateLabelofPB ULPB;
    

    //namedWindow("Labeled PB", CV_WINDOW_KEEPRATIO);





    while(1)
    {

        Rect temproi;
        temproi = PB.SelectROI(ColorLabelImage);
        tempname = "selected roi";
        namedWindow(tempname,CV_WINDOW_KEEPRATIO);
        imshow(tempname,src_ub(temproi));

        LR.setModal(true);
        LR.exec();

        int k = 0;
        for(int i=0;i<contours.size();i++)
        {
            if(hierarchy[i][3] == -1)
            {
                vector<Point> contours_poly;
                Rect BoundRect;
                approxPolyDP( Mat(contours[i]), contours_poly, 3, true );
                BoundRect = boundingRect( Mat(contours_poly) );
                if(RT.FindOverlappingRectangles(temproi,BoundRect) == 2);
                {
                    if(LabelFlag[k] == true) // if already labelled .... need to update
                    {
                        cflag = false;
                        QMessageBox::information(0,"Labelling","Labelling of Processing block is "+Labels[k]);
                        namedWindow("PB",CV_WINDOW_KEEPRATIO);
                        imshow("PB",Blocks[k]);
                        ULPB.setModal(true);
                        ULPB.exec();
                        if(cflag)   // if label of PB changed
                        {
                            //SelectLabel sl;

                           // sl.exec();

                            LabelCount[PBLabel[k]] = LabelCount[PBLabel[k]] - 1;
                            LabelCount[selectedlabel] = LabelCount[selectedlabel] + 1;
                            for(int m=BoundRect.y;m<BoundRect.y+BoundRect.height;m++)
                            {
            
                                for(int n=BoundRect.x;n<BoundRect.x+BoundRect.width;n++)
                                {
                                    bool measure_dist;
                                    if((pointPolygonTest(contours_poly,Point(n,m),measure_dist) > 0.0) && src_binary.data[m*src_binary.cols+n]==0)
                                    {
                                        LabelImages[PBLabel[k]].data[m*ColorLabelImage.cols+n] = 255;
                                        LabelImages[selectedlabel].data[m*ColorLabelImage.cols+n] = 0;
                                        ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+0] = LabelColor[selectedlabel][0];
                                        ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+1] = LabelColor[selectedlabel][1];
                                        ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+2] = LabelColor[selectedlabel][2];
                                    }
                                }
                            }
                            PBLabel[k] = selectedlabel;
                            QMessageBox::information(0,"Labelling","Labelling of Processing block is updated to "+Labels[selectedlabel]);

                        }
                        destroyWindow("PB");
                    }
                    else // if not labelled yet
                    {
                        namedWindow("PB",CV_WINDOW_KEEPRATIO);
                        imshow("PB",Blocks[k]);

                      //  SelectLabel sl;
        
                      //  sl.exec();

                        LabelCount[selectedlabel] = LabelCount[selectedlabel] + 1;

                        PBLabel[k] = selectedlabel;
                        UnlabelledPB = UnlabelledPB - 1;
                        LabelFlag[k] = true;

                        for(int m=BoundRect.y;m<BoundRect.y+BoundRect.height;m++)
                        {

                            for(int n=BoundRect.x;n<BoundRect.x+BoundRect.width;n++)
                            {
                                bool measure_dist;
                                if((pointPolygonTest(contours_poly,Point(n,m),measure_dist) > 0.0) && src_binary.data[m*src_binary.cols+n]==0)
                                {
                                    LabelImages[selectedlabel].data[m*ColorLabelImage.cols+n] = 0;
                                    ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+0] = LabelColor[selectedlabel][0];
                                    ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+1] = LabelColor[selectedlabel][1];
                                    ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+2] = LabelColor[selectedlabel][2];
                                }
                            }
                        }

                        destroyWindow("PB");
                    }

                }
                k = k + 1;
            }
        }
        cflag = false;

        Continue Con;
        Con.setModal(true);
        Con.exec();

        if(!cflag || UnlabelledPB == 0) // if
        {
            break;

        }


    }


    if(UnlabelledPB == 0) // labelling of all PB is done
    {
        ChageLabelofPBs CLPB;
        this->close();
        QMessageBox::information(0,"Labelling","Labelling of All Processing block are done");
        CLPB.setModal(true);
        CLPB.exec();

    }
    else
    {
        QMessageBox::information(0,"Labelling","Labelling of All Processing block are not done");
        this->close();
        LabelProcessingBlock lpb;
        lpb.setModal(true);
        lpb.exec();

    }




}


