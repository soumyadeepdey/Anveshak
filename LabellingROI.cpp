
#include "myheader.h"
#include "groundtruth.h"
#include "ui_groundtruth.h"
#include "selectlabel.h"
#include "QMessageBox"
#include "selectroilabellingtype.h"
#include "relabelchoosingroi.h"
#include "wanttorelabelroi.h"
#include "labelprocessingblocks.h"

//using namespace IITkgp_functions;

/*---------------------------------------Labeling of Processing Blocks within ROI---------------------------------------------*/


/*
 * @Func:LabelPBWithinROI
 * @brief: Label Processing Block Within A Selected ROI
 *
 */


void IITkgp_functions::ProcessingBlocks::LabelPBWithinROI(void)
{
    IITkgp_functions::ProcessingBlocks pb;
    IITkgp_functions::LabellingROI lr;
    SelectLabel sl;


        SelectROILabellingType slrlt;
        slrlt.setModal(true);
        slrlt.exec();




    Rect ROI;
    ROI = pb.SelectROI(ColorLabelImage); // Selecting a region of interest
    
    if(ROI.x<0)
      ROI.x = 0;
    if(ROI.y<0)
      ROI.y = 0;
    if(ROI.x+ROI.width>src_ub.cols)
      ROI.width = src_ub.cols-ROI.x;
    if(ROI.y+ROI.height>src_ub.rows)
      ROI.height = src_ub.rows-ROI.y;

    char *name = "selected roi";
    namedWindow(name,CV_WINDOW_KEEPRATIO);
    imshow(name,src_ub(ROI));

    if(radiobottonnum == 1) // label all PB with a label
    {
       sl.setModal(true);
       sl.exec();

       //LabellingROI::GiveSameLabelToAllPb(ROI,selectedlabel);


       lr.GiveSameLabelToAllPb(ROI,selectedlabel);



       //destroyWindow(name);
    }
    if(radiobottonnum == 2) // label all Unlabelled Pb with a label
    {
        sl.setModal(true);
        sl.exec();

        lr.GiveSameLabelToUnlabelledPB(ROI,selectedlabel);

        //destroyWindow(name);
    }
    if(radiobottonnum == 3) // label PB with different label
    {
       // destroyWindow(name);

        lr.GiveDiffLabelToPB(ROI);
    }

    destroyWindow(name);






}
