


#include "myheader.h"
#include "groundtruth.h"
#include "ui_groundtruth.h"
#include "selectlabel.h"
#include "labelprocessingblock.h"
#include "continuelabeling.h"
#include "QMessageBox"

/*-------------------------------------------------------------------------------------------------------*/


void IITkgp_functions::ProcessingBlocks::LabelPB(void)
{
    LabelProcessingBlock lpb;
    continuelabeling cl;
    SelectLabel sl;
    int k = 0;
    for(int i=0;i<contours.size();i++)
    {
        if(hierarchy[i][3] == -1)
        {

            if(!LabelFlag[k])
            {
                namedWindow("Label",CV_WINDOW_KEEPRATIO);
                imshow("Label",Blocks[k]);
                sl.setModal(true);
                sl.exec();
                LabelFlag[k] = true;
                UnlabelledPB = UnlabelledPB - 1;

                cl.setModal(true);
                cl.exec();
                waitKey(0);
            }

            k++;
        }
    }



}
