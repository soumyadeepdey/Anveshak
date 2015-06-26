#include "selectroilabellingtype.h"
#include "ui_selectroilabellingtype.h"
#include "myheader.h"
#include "QMessageBox"

SelectROILabellingType::SelectROILabellingType(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectROILabellingType)
{
    ui->setupUi(this);
}

SelectROILabellingType::~SelectROILabellingType()
{
    delete ui;
}

void SelectROILabellingType::on_pushButton_clicked()
{

    if(ui->radioButton->isChecked()) //
    {
        QMessageBox::information(0,"ROI Labelling Type","Going To Label all PB Within a ROI  With A Single Label");
        radiobottonnum = 1;
    }
    if(ui->radioButton_2->isChecked())
    {
        QMessageBox::information(0,"ROI Labelling Type","Going To Label all unlabelled PB Within a ROI  With A Single Label");
        radiobottonnum = 2;
    }
    if(ui->radioButton_3->isChecked())
    {
        QMessageBox::information(0,"ROI Labelling Type","Going To Label all PB Within a ROI  With A User Defined Different Labels");
        radiobottonnum = 3;
    }

    this->close();
}
