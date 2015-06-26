

#include "myheader.h"
#include "groundtruth.h"
#include "ui_groundtruth.h"

/*------------------------------------------------------------------------------------------------------------------*/

vector<vector<Point> > contours;
vector<Vec4i> hierarchy;



int NoOfPB;
int UnlabelledPB;
int *PBLabel;
bool *LabelFlag;
vector<Mat> Blocks;
vector<bool> validblock;
Mat ColorLabelImage;

Mat IITkgp_functions::ProcessingBlocks::FindProcessingBlocks(Mat image)
{
    Mat temp_img;

    image.copyTo(temp_img);
     // erosion_dst.copyTo(temp_img);
     // VGImage.copyTo(temp_img);
     // VGImage.release();

    IITkgp_functions::ImageProcFunc IP;

    temp_img = IP.FindImageInverse(temp_img);

      /// Find contours
    findContours( temp_img, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
    temp_img.release();

    /// Approximate contours to polygons + get bounding rects and circles



    vector<vector<Point> > contours_poly( contours.size() );
    vector<Rect> boundRect( contours.size() );

    for( int j = 0; j < contours.size(); j++ )
    {
        approxPolyDP( Mat(contours[j]), contours_poly[j], 3, true );
        boundRect[j] = boundingRect( Mat(contours_poly[j]) );
        validblock.push_back(false);
    }

    Mat drawing;
    src_ub.copyTo(drawing);
    RNG rng(12345);
    int number_of_block = 0;
    for( int j = 0; j< contours.size(); j++ )
    {

      if(hierarchy[j][3] == -1)
      {

          int v1 = rng.uniform(0, 255);
          int v2 = rng.uniform(0, 255);
          int v3 = rng.uniform(0, 255);
          int p,q;
          p = 0;
          Mat TempC = Mat(boundRect[j].height,boundRect[j].width,CV_8UC3,Scalar(255,255,255));
          int temp_pixel = 0;
          for(int m=boundRect[j].y;m<boundRect[j].y+boundRect[j].height;m++)
          {
              q = 0;
              for(int n=boundRect[j].x;n<boundRect[j].x+boundRect[j].width;n++)
              {
                  int temp_col = boundRect[j].width;

                  bool measure_dist;
                  if((pointPolygonTest(contours_poly[j],Point(n,m),measure_dist) > 0.0) && src_binary.data[m*src_binary.cols+n]==0)
                  {
                      temp_pixel = temp_pixel + 1;
                      drawing.data[(m*drawing.cols+n)*3+0] = v1;
                      drawing.data[(m*drawing.cols+n)*3+1] = v2;
                      drawing.data[(m*drawing.cols+n)*3+2] = v3;

                      TempC.data[(p*temp_col+q)*3+0] = src_ub.data[(m*src.cols+n)*3+0];
                      TempC.data[(p*temp_col+q)*3+1] = src_ub.data[(m*src.cols+n)*3+1];
                      TempC.data[(p*temp_col+q)*3+2] = src_ub.data[(m*src.cols+n)*3+2];
                  }
                  q++;

              }
              p++;
          }

          if(temp_pixel > 2)
          {
            number_of_block = number_of_block + 1;
            Blocks.push_back(TempC);
            validblock[j] = true;
          }
          TempC.release();

      }
    }

    NoOfPB = number_of_block;
    UnlabelledPB = NoOfPB;
    PBLabel = (int *)malloc(NoOfPB*sizeof(int));
    LabelFlag = (bool *)malloc(NoOfPB*sizeof(bool));

    for(int i=0;i< NoOfPB;i++)
        LabelFlag[i] = false;
    
    src_ub.copyTo(ColorLabelImage);
    
    
    

    return(drawing);

    




}
