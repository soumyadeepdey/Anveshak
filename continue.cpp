#include "continue.h"
#include "ui_continue.h"
#include "myheader.h"

Continue::Continue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Continue)
{
    ui->setupUi(this);
}

Continue::~Continue()
{
    delete ui;
}



void Continue::on_pushButton_2_clicked() // no
{
    cflag = false;
    this->close();
}

void Continue::on_pushButton_clicked() //yes
{
    cflag = true;
    this->close();
}
