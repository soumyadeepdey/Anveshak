#include "undopreprocessing.h"
#include "ui_undopreprocessing.h"
#include "myheader.h"
#include "QMessageBox"
#include "preprocessingblock.h"
#include "labelinfo.h"

UndoPreprocessing::UndoPreprocessing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UndoPreprocessing)
{
    ui->setupUi(this);
}

UndoPreprocessing::~UndoPreprocessing()
{
    delete ui;
}

void UndoPreprocessing::on_pushButton_clicked() // Yes
{
    destroyWindow("Processing Blocks");
    src_binary.copyTo(ResultImage);
    src_binary.copyTo(PreProcessedImage);
    QMessageBox::information(0,"Undo Operation","Preprocessing is undone and reverted to binary image");
    PreProcessingBlock PPB;
    PPB.setModal(true);
    PPB.exec();
    this->close();
}

void UndoPreprocessing::on_pushButton_2_clicked() // No
{
    destroyWindow("Processing Blocks");
    
    ResultImage.release();
    PreProcessedImage.release();

    
    QMessageBox::information(0,"Preprocessing","Preprocessing is done, now label each Processing Block");
    this->close();
    LabelInfo LI;
    LI.setModal(true);
    LI.exec();

}
