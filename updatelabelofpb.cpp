#include "updatelabelofpb.h"
#include "ui_updatelabelofpb.h"
#include "myheader.h"

UpdateLabelofPB::UpdateLabelofPB(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateLabelofPB)
{
    ui->setupUi(this);
}

UpdateLabelofPB::~UpdateLabelofPB()
{
    delete ui;
}

void UpdateLabelofPB::on_pushButton_2_clicked() //no
{
    cflag = false;
    this->close();
}

void UpdateLabelofPB::on_pushButton_clicked() // Yes
{
    cflag = true;
    this->close();
}
