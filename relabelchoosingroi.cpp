#include "relabelchoosingroi.h"
#include "ui_relabelchoosingroi.h"
#include "myheader.h"
#include "selectlabel.h"
#include "QMessageBox"

ReLabelChoosingROI::ReLabelChoosingROI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReLabelChoosingROI)
{
    ui->setupUi(this);

    namedWindow("Labelled Processing Blocks", CV_WINDOW_KEEPRATIO);
    imshow("Labelled Processing Blocks",ColorLabelImage);
}

ReLabelChoosingROI::~ReLabelChoosingROI()
{
    delete ui;
}

void ReLabelChoosingROI::on_pushButton_2_clicked() // if labelling is finalized
{
    destroyWindow("Labelled Processing Blocks");
    this->close();
    IITkgp_functions::WriteOutput wo;
    wo.FinalOutput();
}

void ReLabelChoosingROI::on_pushButton_clicked() // Re Label by selecting ROI
{
    this->setEnabled(false);

    destroyWindow("Labelled Processing Blocks");

    QMessageBox::information(0,"Cropping Method","Select a Bounding Box And then press 's' to finalize the selection ");

    IITkgp_functions::ProcessingBlocks pb;
    pb.LabelPBWithinROI();

    this->setEnabled(true);


    ReLabelChoosingROI RLCR;
    this->close();
    RLCR.setModal(true);
    RLCR.exec();
}
