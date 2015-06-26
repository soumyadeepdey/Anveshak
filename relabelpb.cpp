#include "relabelpb.h"
#include "ui_relabelpb.h"
#include "myheader.h"

ReLabelPB::ReLabelPB(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReLabelPB)
{
    ui->setupUi(this);
}

ReLabelPB::~ReLabelPB()
{
    delete ui;
}
