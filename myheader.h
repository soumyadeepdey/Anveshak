#ifndef MYHEADER_H
#define MYHEADER_H



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include <sys/stat.h>
#include <iostream>
#include <time.h>


#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
//#include "opencv2/highgui/highgui.hpp"
#include "opencv2/nonfree/features2d.hpp"


#include <opencv/cv.h>
#include <opencv/highgui.h>

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

#define PI 3.14159265

#include "groundtruth.h"



/*-------------------------------------------------------- Structure Declarations--------------------------------------------------------*/


struct BeanStucture{
  int BeanNumber;
  int MaxElement;
  int LowerBound;
  int UpperBound;
  int middle;
};

struct Ray {
        Point2i p;
        Point2i q;
        vector<Point2i> points;
    int dist;
    void CalcEcluiDist()
    {
      dist =(int) sqrt( ((p.x - q.x)*(p.x-q.x)) + ((p.y-q.y)*(p.y-q.y)) );
    }
};


typedef struct imagestructure
{
    int x;
    int y;
    int label;
    int value;
    int mapped;

}is;


typedef struct connected_component
{
    struct imagestructure im;
    struct connected_component *nxt;
}cc;



typedef struct numberofcc
{
    struct connected_component *start;
    struct connected_component *last;
    float gray_hist[256];
    /*int text_nontext
     * @value : 0 if text
     *          1 if non_text
     */
    int text_nontext;
    /*int label
     * @value : value of the color label from k-mean
     */
    int label;
    int number_of_component;
    int flag;
    int xmin;
    int ymin;
    int xmax;
    int ymax;
    int centroidx;
    int centroidy;
    int blk_no;
    int valid_blk_no;
    float histogram[256];
    double mean;
    double var;
    double std_dev;
    double skew;
    void calc_centroid()
    {
      centroidx =  xmin+((xmax-xmin)/2);
      centroidy =  ymin+((ymax-ymin)/2);
    }
    void calc_hist()
    {

      for(int i=0;i<256;i++)
        histogram[i]=gray_hist[i]/number_of_component;
    }

    void calc_mean()
    {
      mean = 0;
      for(int i=0;i<256;i++)
      {
        mean = mean + (gray_hist[i]*i);
      }
      mean = mean/number_of_component;
    }


    void calc_dev()
    {
      calc_mean();
      int temp;
      std_dev = 0.0;
      var = 0.0;
      skew = 0.0;
      for(int i=0;i<256;i++)
      {
        for(int j=0;j<gray_hist[i];j++)
        {
          temp = i - mean;
          var = var + (temp * temp);
          skew = skew + (temp * temp *temp);
        }
      }

      var = var / number_of_component;
      std_dev = sqrt(var);

    }

    void calc_distribution()
    {
      calc_hist();
      calc_mean();
      calc_dev();
    }

}nocc;


extern int NoOfLabels;
extern int NoOfPB;
extern int UnlabelledPB;

extern int *PBLabel;
extern int selectedlabel;

extern int *(*LabelColor);

extern Mat src,src_gray,src_binary,src_ROI,src_ub;
extern Mat PreProcessedImage;
extern Mat ResultImage;
extern Mat ColorLabelImage;
extern char *substring;
extern char *tempname;
extern const char *imagename;

extern vector<Mat> LabelImages;
extern Mat LabelImageInOne;


extern vector<vector<Point> > contours;
extern vector<Vec4i> hierarchy;


extern vector<QString> Labels;

extern bool *LabelFlag;

extern vector<Mat> Blocks;
extern int *LabelCount;

extern bool cflag;

extern RNG rng;

extern int radiobottonnum;

extern vector<bool> validblock;



/*-----------------------------------------------------------------------------------------------------------------*/

namespace IITkgp_functions {


class statistical_analysis
{


public :

    /**
     * @function FindMean
     * @param input Single Channel Mat data
     * @brief Calculate Mean of Given data array
     * @return mean(double) of the given array
     */
    double FindMean(Mat data);


/**
 * @function FindVar
 * @param input Single Channel Mat data
 * @brief Calculate variance of Given data array
 * @return Variance(double) of the given array
 */
    double FindVar(Mat data);



/**
 * @function FindStdDev
 * @param input Single Channel Mat data
 * @brief Calculate Standard Deviation of Given data array
 * @return Standard Deviation(double) of the given array
 */
    double FindStdDev(Mat data);

/**
 * @function FindSkew
 * @param input Single Channel Mat data
 * @brief Calculate Skewness of Given data array
 * @return Skewness(double) of the given array
 */
    double FindSkew(Mat data);


/**
 * @function FindMinElementPosi
 * @param input Single Channel Mat data and pointer to min element  and its position
 * @brief Calculate Min value of Given data array and its position
 *
 */
    void FindMinElementPosi(Mat data, double *value, int *posi);

/**
 * @function FindMaxElement
 * @param input Single Channel Mat data and pointer to max element and pointer to position
 * @brief Calculate Max value of Given data array and its position
 *
 */
    void FindMaxElementPosi(Mat data, double *value, int *posi);

/**
 * @function FindHistogram
 * @param input Single Channel Mat data
 * @brief Calculate Histogram of the data
 * @return Histogram data of the element
 */
    Mat FindHistogram(Mat data);

/**
 * @function DrawHistogram
 * @param input Single Channel Mat data
 * @brief Calculate Histogram of the data and Draw it
 *
 */
    void DrawHistogram(Mat data);



};


class BinaryImage
{
public:

        //void BinaryThreshold( int, void* );

        /**
         * @function binarization
         * @param input an image in Mat format and type for binarization
         * @brief type = 1 for adaptive
         * @brief type = 2 for otsu
         * @brief type = 3 for Normal Threshold by GUI
         * @brief type = 4 for Normal Threshold by fixed value
         * @return Return a binary image of Mat data-type
          */
        Mat binarization(Mat image, int type);


};

class ImageProcFunc
{
public:

    /**
     * @function foreground_masked_image
     * @param input a color image in Mat format and it's corresponding binary image
     * @brief convert an input image into a uniform background image
     * @brief masked the foreground pixels and make the background pixel uniform
     * @return Return a uniform background image of Mat data-type
     */
    Mat foreground_masked_image(Mat ColorImage, Mat binary);

    /**
     * @function NumberofForegroundPixel
     * @param input a binary image in Mat format
     * @brief It count number of foreground pixel in the given image
     * @return Return a integer which gives the count of number of foreground pixel
     */
    int NumberofForegroundPixel(Mat image);

    /**
     * @function FindImageInverse
     * @param input Mat data(image)
     * @brief Calculate inverse of a given image (255 - image.data[i])
     * @return inverse image(Mat)
     */
    Mat FindImageInverse(Mat image);

};

class folder
{
public:
    /**
     * @function input_image_name_cut
     * @param : input param: input-name to be cut upto '.'
     * @return : input name upto '.'
     *
     */

    char* input_image_name_cut(const char *s);

    /**
     * @function makedir
     * @param input a character string
     * @brief it create a directry of given character string
     */
    void makedir(char *name);

    /**
     * @function CreateNameIntoFolder
     * @param  input Foldername, desired name
     * @return : name within the desired folder
     *
     */

    char* CreateNameIntoFolder(char *foldername, char *desiredname );
};

class PixelValidation
{
public:
    /**
     * @function validate
     * @param : input param: co-ordinate position(i,j) and maximum-limit(t) row, col
     * @brief : co-ordinate position(i,j) to be check whether it is within given row and col
     * @return : 1 if it belong to particular region
     *           0 if not belong within that particular row and col
     */
    int validate(int i, int j, int row, int col);
};

class CC_analysis
{
 public:
    /**
     * @function labelingdfs
     * @param : input param: input image structure(of (IS(datatype))) input co-ordinate(m,n) to belabeled and image dimention(row,col)
     * @brief : labeling based on DFS algorithm
     * @return : image structure(of (IS(datatype)))
     */
    is ** labelingdfs(is **tempstructuredimage,int *m, int *n, int temp_row, int temp_col);

    /**
     * @function cclabeling
     * @param : input param: input image structure(of (IS(datatype))) and image dimention(row,col)
     * @brief : labeling of ConnectedComponent based on DFS algorithm
     * @return : image structure(of (IS(datatype)))
     */


    is** cclabeling(is **tempstructuredimage,int temp_row, int temp_col);

    /**
     * @function FindConnectedComponent
     * @param : input param: input image(binary) Mat data-type
     *                             src_gray(gray scale) Mat data-type
     * @brief : Find connected component from the input binary image
     * @return : array of connected components (nocc(data-type))
     */


    nocc* FindConnectedComponent(Mat image, Mat src_gray);
};

class Morphology
{
public:
    /**
     * @function erosion
     * @param input an image(binary) in Mat format
     * @brief it erode an image with a square mask of 3x3
     * @return Return eroded image of Mat data-type
     */

    Mat erosion(Mat image);


    /**
     * @function boundaryextraction
     * @param input an image(binary) in Mat format
     * @brief it find the boundary of the input image
     * @return Return boundary of input image(binary in nature)
     */

    Mat boundaryextraction(Mat image);

    /**  @function Erosion
     * @param input
     * element type
     * 0: kernel = Rectangle
     * 1: kernel = CROSS
     * 2: kernel = ELLIPSE
     * @param input erosion Size(n) : Create a kernel or window of 2n+1
     * @param input an image in Mat format(image).
     * @brief it find Eroded Image of the input image with given kernel type and size
     * @return Return Eroded image of input image
     */
    Mat Erosion( int erosion_elem, int erosion_size, Mat image);

    /**  @function Dilation
     * @param input
     * element type
     * 0: kernel = Rectangle
     * 1: kernel = CROSS
     * 2: kernel = ELLIPSE
     * @param input Dilation Size(n) : Create a kernel or window of 2n+1
     * @param input an image in Mat format(image).
     * @brief it find Dilated Image of the input image with given kernel type and size
     * @return Return Dilateded image of input image
     */
    Mat Dilation( int dilation_elem, int dilation_size, Mat image );

    /**  @function Open
     * @param input
     * element type
     * 0: kernel = Rectangle
     * 1: kernel = CROSS
     * 2: kernel = ELLIPSE
     * @param input element Size(n) : Create a kernel or window of 2n+1
     * @param input an image in Mat format(image).
     * @brief it find Open Image of the input image with given kernel type and size
     * @return Return Open image of input image
     */
    Mat Open(int open_elem, int open_size, Mat image);

    /**  @function Close
     * @param input
     * element type
     * 0: kernel = Rectangle
     * 1: kernel = CROSS
     * 2: kernel = ELLIPSE
     * @param input element Size(n) : Create a kernel or window of 2n+1
     * @param input an image in Mat format(image).
     * @brief it find Close Image of the input image with given kernel type and size
     * @return Return Close image of input image(binary in nature)
     */
    Mat Close(int close_elem, int close_size, Mat image);


    /**  @function Morphology_Gui
     * @param input
     *                 Mat image
     *                 int type
     *                  0: Erosion
     *                  1: Dilation
     *                  2: Open
     *                  3: Close
     *
     * @return Return Morphologycally processed image
     */

    Mat Morphology_Gui(Mat image, int type);

};

class SmoothingGapfilling
{
public:
    /**
     * @function horizontal_smoothing
     * @param input an image(binary) in Mat format and integer value whitespace that need to be smoothen or filled up
     * @brief with this function from a foreground position , next whitespace number of pixel is filled in horizontal direction
     * @brief it produce smoothed image of the input image in horizontal direction by filling up with foreground with whitespace amount
     * @return Return horizontally smoothed image of input image(binary in nature)
     */

    Mat horizontal_smoothing(Mat image, int whitespace);

    /**
     * @function horizontal_gapfilling
     * @param input an image(binary) in Mat format and integer value whitespace that need to be smoothen or filled up
    * @brief with this function gap btween two foreground pixel is filled only if the gap between two foreground pixel in horizontal direction has a gap less than or equal to whitespace
     * @brief it produce smoothed image of the input image in horizontal direction by filling up with foreground with whitespace amount
     * @return Return gap-filled image of input image(binary in nature)
     */

    Mat horizontal_gapfilling(Mat image, int whitespace);

    /**
     * @function vertical_smoothing
     * @param input an image(binary) in Mat format and integer value whitespace that need to be smoothen or filled up
     * @brief with this function from a foreground position , next whitespace number of pixel is filled
     * @brief it produce smoothed image of the input image in vertical direction by filling up with foreground with whitespace amount
     * @return Return vertically smoothed image of input image(binary in nature)
     */

    Mat vertical_smoothing(Mat image,int whitespace);

    /**
     * @function vertical_gapfilling
     * @param input an image(binary) in Mat format and integer value whitespace that need to be gap filled or filled up
     * @brief with this function gap btween two foreground pixel is filled only if the gap between two foreground pixel in vertival direction has a gap less than or equal to whitespace
     * @brief it produce gap filled image of the input image in vertical direction by filling up with foreground with whitespace amount
     * @return Return vertically gap-filled image of input image(binary in nature)
     */


    Mat vertical_gapfilling(Mat image,int whitespace);



    Mat smoothinggapfilling_GUI(Mat image, int sgtype);

};

class HSV
{
public:

    /**
     * @function calculate_value
     * @param input RGB value of a pixel
     * @brief Calculate value from RGB values
     * @return Value calculated from RGB values of a pixel
     */


    double calculate_value(int R, int G, int B);

    /**
     * @function calculate_minimum
     * @param input three integer value
     * @brief Calculate minimum between 3 integer value
     * @return Minimum integer value among the 3
     */

    int calculate_minimum(int a, int b, int c);

    /**
     * @function calculate_saturation
     * @param input RGB values of a pixel
     * @brief Calculate saturation from RGB values of a pixel
     * @return calculated S value
     */

    double calculate_saturation(int R, int G, int B);

    /**
     * @function calculate_theta
     * @param input RGB values of a pixel
     * @brief Calculate angle in H domain from given RGB values of a pixel
     * @return calculated theta value
     */

    double calculate_theta(int R, int G, int B);

    /**
     * @function calculate_hue
     * @param input RGB values of a pixel
     * @brief Calculate hue from given RGB values of a pixel
     * @return calculated H value
     */


    double calculate_hue(int R, int G, int B);

    /**
     * @function FindHSVImage
     * @param input RGB color Image
     * @brief Calculate HSV image from the Color RGB image
     * @return calculated HSV image
     */


    Mat FindHSVImage(Mat colorimage);

    /**
     * @function FindNormalizeSaturation
     * @param input Saturated data(double)
     * @brief Calculate normalized saturation value from double value
     * @return calculated S value
     */


    int FindNormalizeSaturation(double saturation);

    /**
     * @function FindNormalizeHue
     * @param input Hue data (value)
     * @brief Calculate normalized Hue value from double value
     * @return calculated H value
     */


    int FindNormalizeHue(double hue);

    /**
     * @function FindHSVImage
     * @param input RGB color Image
     * @brief Calculate nOrmalized HSV image (Range 0-255) from the Color RGB image
     * @return calculated normalized HSV image
     */


    Mat FindNormalizedHSVImage(Mat colorimage);


};

class RectangleTest
{
public:
    /**
     * @Function: PointRectangleTest
     * @brief : Take 1 rectangle and a Point as input
     * @brief : Test whether the Given Point is inside the Given Rectangle or Inside
     * @return : 	0: Point is Outside of Rectangle
     * 		1: Point is inside the given Rectangle
     * */

    int PointRectangleTest(Rect GivenRect, Point GivenPoint);

    /**
     * @Function: FindOverlappingRectangles
     * @brief : Take 2 rectangle as an input
     * @return : 	0: Rect 1 and Rect 2 are disjoint
     * 		1: Rect 1 is inside Rect 2
     * 	    	2: Rect 2 is inside Rect 1
     * 	    	3: Rect 1 and 2 are partly overlapped
     *
     *
     * */

    int FindOverlappingRectangles(Rect first, Rect second);
};


class LabellingROI
{
public:

    void GiveSameLabelToAllPb(Rect ROI, int label);

    void GiveSameLabelToUnlabelledPB(Rect ROI, int label);

    void GiveDiffLabelToPB(Rect ROI);
};

class ProcessingBlocks
{
public:

    Mat FindProcessingBlocks(Mat image);

    Rect SelectROI(Mat image);

    void LabelIndividualPB(void);

    void LabelPBWithinROI(void);
};



class WriteOutput
{
public:

    void FinalOutput(void);
};

}

#endif // MYHEADER_H
