#include "continuelabeling.h"
#include "ui_continuelabeling.h"
#include "myheader.h"
#include "labelprocessingblock.h"

continuelabeling::continuelabeling(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::continuelabeling)
{
    ui->setupUi(this);
}

continuelabeling::~continuelabeling()
{
    delete ui;
}

void continuelabeling::on_pushButton_clicked() // continue
{
    this->close();
}



void continuelabeling::on_pushButton_2_clicked() // cancel
{
    cflag = true;
    this->close();
}
