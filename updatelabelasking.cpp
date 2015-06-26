#include "updatelabelasking.h"
#include "ui_updatelabelasking.h"
#include "myheader.h"

UpdateLabelAsking::UpdateLabelAsking(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateLabelAsking)
{
    ui->setupUi(this);
}

UpdateLabelAsking::~UpdateLabelAsking()
{
    delete ui;
}

void UpdateLabelAsking::on_pushButton_clicked() //Yes
{
    cflag = true;
    this->close();
}

void UpdateLabelAsking::on_pushButton_2_clicked() //No
{
    cflag = false;
    this->close();
}
