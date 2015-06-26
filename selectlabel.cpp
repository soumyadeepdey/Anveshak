#include "selectlabel.h"
#include "ui_selectlabel.h"
#include "myheader.h"
#include "QMessageBox"

int selectedlabel;

SelectLabel::SelectLabel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectLabel)
{
    ui->setupUi(this);
    for(int i=0;i<Labels.size();i++)
        ui->comboBox->addItem(Labels[i]);
}

SelectLabel::~SelectLabel()
{
    delete ui;
}

void SelectLabel::on_pushButton_clicked() // select
{
    int p;
    p = ui->comboBox->currentIndex();
    selectedlabel = p;
   
    QString Slabel = ui->comboBox->currentText();
    QMessageBox::information(0,"Selected Label","Label "+Slabel+" is selected");
    //destroyWindow(tempname);
    this->close();
}
