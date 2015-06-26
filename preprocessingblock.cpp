#include "preprocessingblock.h"
#include "ui_preprocessingblock.h"

#include "myheader.h"
#include "QMessageBox"

#include "undopreprocessing.h"

PreProcessingBlock::PreProcessingBlock(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreProcessingBlock)
{
    ui->setupUi(this);
}

PreProcessingBlock::~PreProcessingBlock()
{
    delete ui;
}

IITkgp_functions::folder folderobj;
Mat PreProcessedImage;



void PreProcessingBlock::on_pushButton_clicked() // select (morphological operation)
{
    this->setEnabled(false);

    int MorphologicalOperation;
    if(ui->radioButton->isChecked())
    {
        QMessageBox::information(0,"Morphological Operation","Erosion is selected");
        MorphologicalOperation = 0;
    }
    if(ui->radioButton_2->isChecked())
    {
        QMessageBox::information(0,"Morphological Operation","Dilation is selected");
        MorphologicalOperation = 1;
    }
    if(ui->radioButton_3->isChecked())
    {
        QMessageBox::information(0,"Morphological Operation","Open is selected");
        MorphologicalOperation = 2;
    }
    if(ui->radioButton_4->isChecked())
    {
        QMessageBox::information(0,"Morphological Operation","Close is selected");
        MorphologicalOperation = 3;
    }


    ResultImage.copyTo(PreProcessedImage);
    IITkgp_functions::Morphology MorOp;
    ResultImage = MorOp.Morphology_Gui(PreProcessedImage,MorphologicalOperation);
    namedWindow("Preprocessed Image",CV_WINDOW_KEEPRATIO);
    imshow("Preprocessed Image",ResultImage);
    waitKey(0);
    this->setEnabled(true);



}

void PreProcessingBlock::on_pushButton_2_clicked() // Done
{
    destroyWindow("Preprocessed Image");
    /*
    char *name;
    name = (char *) malloc ( 2001 * sizeof(char));
      if(name == NULL)
      {
        printf("Memory can not be allocated\n");
        exit(0);
      }
      name = folderobj.CreateNameIntoFolder(substring,"PreProcessedImage.png");
      imwrite(name,ResultImage);
      */
      ResultImage.copyTo(PreProcessedImage);

      Mat drawing;
      IITkgp_functions::ProcessingBlocks PB;
      drawing = PB.FindProcessingBlocks(PreProcessedImage);

      namedWindow("Processing Blocks",CV_WINDOW_KEEPRATIO);
      imshow("Processing Blocks",drawing);
      //waitKey(0);

      this->close();

      UndoPreprocessing UPP;
      UPP.setModal(true);
      UPP.exec();



}

void PreProcessingBlock::on_pushButton_3_clicked() // Boundary extraction
{
    this->setEnabled(false);

    IITkgp_functions::Morphology MorOp;
    PreProcessedImage = MorOp.boundaryextraction(ResultImage);
    PreProcessedImage.copyTo(ResultImage);
    PreProcessedImage.release();
    char *name;
    name = (char *) malloc ( 2001 * sizeof(char));
      if(name == NULL)
      {
        printf("Memory can not be allocated\n");
        exit(0);
      }
      name = folderobj.CreateNameIntoFolder(substring,"PreProcessedImage.png");
      imwrite(name,ResultImage);
      namedWindow("Preprocessed Image",CV_WINDOW_KEEPRATIO);
      imshow("Preprocessed Image",ResultImage);
      waitKey(0);
      this->setEnabled(true);


}

void PreProcessingBlock::on_pushButton_4_clicked() // select (smoothing or gapfilling)
{
    this->setEnabled(false);
    int sgtype;
    //int direction;
    if(ui->radioButton_5->isChecked()) // smoothing
    {
        QMessageBox::information(0,"Preprocessing Technique","Smoothing is selected");
        sgtype = 0;


    }
    if(ui->radioButton_6->isChecked()) // gapfilling
    {
        QMessageBox::information(0,"Preprocessing Technique","Gapfilling is selected");
        sgtype = 1;


    }

    IITkgp_functions::SmoothingGapfilling SGO;


    ResultImage.copyTo(PreProcessedImage);

    ResultImage = SGO.smoothinggapfilling_GUI(PreProcessedImage,sgtype);

    namedWindow("Preprocessed Image",CV_WINDOW_KEEPRATIO);
    imshow("Preprocessed Image",ResultImage);
    waitKey(0);

    this->setEnabled(true);

}
