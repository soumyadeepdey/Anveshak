#include "labelprocessingblocks.h"
#include "ui_labelprocessingblocks.h"
#include "QMessageBox"
#include "myheader.h"
#include "selectlabel.h"
#include "wanttorelabelroi.h"
#include "relabelchoosingroi.h"
#include "continue.h"


IITkgp_functions::ProcessingBlocks pb;

/*@var LabelingType
 *      1 if Labeling by indivibual blocks
 *      2 if Labeling by selecting a ROI
 * */
int LabelingType;

LabelProcessingBlocks::LabelProcessingBlocks(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LabelProcessingBlocks)
{
    ui->setupUi(this);

    namedWindow("Labelled Processing Blocks", CV_WINDOW_KEEPRATIO);
    imshow("Labelled Processing Blocks",ColorLabelImage);
}

LabelProcessingBlocks::~LabelProcessingBlocks()
{
    delete ui;
}

void LabelProcessingBlocks::on_pushButton_clicked() //Select button
{
    this->setEnabled(false);
    if(ui->radioButton->isChecked()) // Label Indivibual Block is selected
    {
        destroyWindow("Labelled Processing Blocks");

        QMessageBox::information(0,"Labelling Type","Label by labelling individual processing block is selected");
        LabelingType = 1;
        pb.LabelIndividualPB();
    }
    if(ui->radioButton_2->isChecked()) // If Label By ROI is selected
    {
        destroyWindow("Labelled Processing Blocks");
        QMessageBox::information(0,"Labelling Type","Label by labbeling a ROI is selected");

        LabelingType = 2;
      //  while(1)
      //  {
            QMessageBox::information(0,"Cropping Method","Select a Bounding Box And then press 's' to finalize the selection ");
        //    Continue con;
        //    con.setModal(true);
        //    con.exec();

        //    if(!cflag)
         //       break;

            pb.LabelPBWithinROI();

       // }
    }

 /********************After Selecting A radio botton***************************/

    //destroyWindow("Labelled Processing Blocks");
    namedWindow("Labelled Processing Blocks", CV_WINDOW_KEEPRATIO);
    imshow("Labelled Processing Blocks",ColorLabelImage);

    if(UnlabelledPB == 0) // all processing blocks are labelled
    {
        QMessageBox::information(0,"Labeling Status","All Processing Blocks are labelled");



        WantToRelabelROI WTRR;
        WTRR.setModal(true);
        WTRR.exec();

        if(cflag)// Need to Relabel any ROI
        {
            destroyWindow("Labelled Processing Blocks");
            this->close();
            ReLabelChoosingROI RLCR;
            RLCR.exec();

        }
        else // no need to relabel Final labeling is done
        {
            //Done

            destroyWindow("Labelled Processing Blocks");


            this->close();

            IITkgp_functions::WriteOutput wo;
            wo.FinalOutput();
        }

    }
    else // all processing blocks are not labelled
    {
        QMessageBox::information(0,"Labeling Status","All Processing Blocks are not labelled");
       // imshow("Labelled Processing Blocks",ColorLabelImage);
        destroyWindow("Labelled Processing Blocks");
        LabelProcessingBlocks LPB;
        this->close();
        LPB.setModal(true);
        LPB.exec();
    }

    this->setEnabled(true);
}

void LabelProcessingBlocks::on_pushButton_2_clicked() // Done
{
    //destroyWindow("Labelled Processing Blocks");
    namedWindow("Labelled Processing Blocks", CV_WINDOW_KEEPRATIO);
    imshow("Labelled Processing Blocks",ColorLabelImage);

    if(UnlabelledPB == 0) // all processing blocks are labelled
    {
        QMessageBox::information(0,"Labeling Status","All Processing Blocks are labelled");



        WantToRelabelROI WTRR;
        WTRR.setModal(true);
        WTRR.exec();

        if(cflag)// Need to Relabel any ROI
        {
            destroyWindow("Labelled Processing Blocks");
            this->close();
            ReLabelChoosingROI RLCR;
            RLCR.setModal(true);
            RLCR.exec();

        }
        else // no need to relabel Final labeling is done
        {
            //Done

            destroyWindow("Labelled Processing Blocks");


            this->close();


            IITkgp_functions::WriteOutput wo;
            wo.FinalOutput();
        }

    }
    else // all processing blocks are not labelled
    {
        QMessageBox::information(0,"Labeling Status","All Processing Blocks are not labelled");
        //imshow("Labelled Processing Blocks",ColorLabelImage);
        destroyWindow("Labelled Processing Blocks");
        LabelProcessingBlocks LPB;
        this->close();
        LPB.setModal(true);
        LPB.exec();
    }
}
