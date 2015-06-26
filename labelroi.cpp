#include "labelroi.h"
#include "ui_labelroi.h"
#include "myheader.h"
#include "QMessageBox"

LabelROI::LabelROI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LabelROI)
{
    ui->setupUi(this);
    
    for(int i=0;i<Labels.size();i++)
        ui->comboBox->addItem(Labels[i]);
}

LabelROI::~LabelROI()
{
    delete ui;
}



void LabelROI::on_pushButton_clicked() // select
{
    int p;
    p = ui->comboBox->currentIndex();
    selectedlabel = p;
   
    QString Slabel = ui->comboBox->currentText();
    QMessageBox::information(0,"Selected Label","Label "+Slabel+" is selected");
    destroyWindow(tempname);
    this->close();
}


