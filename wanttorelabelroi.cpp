#include "wanttorelabelroi.h"
#include "ui_wanttorelabelroi.h"
#include "myheader.h"

WantToRelabelROI::WantToRelabelROI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WantToRelabelROI)
{
    ui->setupUi(this);
}

WantToRelabelROI::~WantToRelabelROI()
{
    delete ui;
}

void WantToRelabelROI::on_pushButton_clicked() // yes
{
    cflag = true;
    this->close();
}


void WantToRelabelROI::on_pushButton_2_clicked() // no
{
    cflag = false;
    this->close();
}
