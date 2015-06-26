
#include "myheader.h"
#include "groundtruth.h"
#include "ui_groundtruth.h"
#include "continue.h"
#include "selectlabel.h"
#include "relabelchoosingroi.h"

/*---------------------------------------Labeling of Individual Processing Blocks---------------------------------------------*/


/*
 * @Func:LabelIndividualPB
 * @brief: Label Unlabelled Processing Block Individually
 *
 */

void IITkgp_functions::ProcessingBlocks::LabelIndividualPB(void)
{
    Continue con;
    SelectLabel sl;
    int k =0;
    int p = 0;
    for(int i=0;i<contours.size();i++)
    {
        if(hierarchy[i][3] == -1 && validblock[i] == true)
        {


            if(LabelFlag[k] == false)  // If a Block is not labelled
            {
                p = p + 1;
                int sp;
                char *name;
                name = (char *) malloc(2000 * sizeof(char));
                sp = sprintf(name,"Processing Block%d",k);
                tempname = name;
                namedWindow(name, CV_WINDOW_KEEPRATIO);
                Mat Temp;
                Temp = Blocks[k];
                imshow(name, Temp);

                sl.setModal(true);  // select Label
                sl.exec();

                PBLabel[k] = selectedlabel;
                LabelFlag[k] = true;
                UnlabelledPB = UnlabelledPB - 1;
                LabelCount[selectedlabel] = LabelCount[selectedlabel] + 1;

                // Now Give Color To the Labelled PB

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
                            LabelImages[selectedlabel].data[m*ColorLabelImage.cols+n] = 0;
                            LabelImageInOne.data[m*ColorLabelImage.cols+n] = selectedlabel;
                            ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+0] = LabelColor[selectedlabel][0];
                            ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+1] = LabelColor[selectedlabel][1];
                            ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+2] = LabelColor[selectedlabel][2];
                        }
                    }
                }

                con.setModal(true); // Continue labeling Individually
                con.exec();

                if(!cflag) // do not want to continue labeling individual blocks
                    break;


                destroyWindow(name);
                Temp.release();

             }



            k++;
        }
    }





}
