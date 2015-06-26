#include "customizelabels.h"
#include "ui_customizelabels.h"
#include "myheader.h"
#include "QMessageBox"
#include "labelprocessingblocks.h"



CustomizeLabels::CustomizeLabels(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomizeLabels)
{
    ui->setupUi(this);

    for(int i =0;i<Labels.size();i++)
        ui->comboBox->addItem(Labels[i]);
}

CustomizeLabels::~CustomizeLabels()
{
    delete ui;
}

void CustomizeLabels::on_pushButton_clicked() // Add Label
{
    Labels.push_back(ui->lineEdit->text());

    ui->comboBox->addItem(ui->lineEdit->text());
}

void CustomizeLabels::on_pushButton_2_clicked() // Delete Label
{
    int p;
    p = ui->comboBox->currentIndex();
    QString deletestring = ui->comboBox->currentText();
    ui->comboBox->removeItem(p);
    Labels.erase(Labels.begin()+p);

    QMessageBox::information(0,"Delete Label","Label "+deletestring+" is deleted");

}




void CustomizeLabels::on_pushButton_3_clicked() // Done Finalized Label
{

    
    
    LabelCount = (int *)malloc(Labels.size()*sizeof(int));


    LabelColor = (int **)malloc(Labels.size()*sizeof(int *));
    for(int i=0;i<Labels.size();i++)
    {
        LabelColor[i] = (int *)malloc(3 * sizeof(int));
        LabelCount[i] = 0;
    }

    for(int i=0;i<Labels.size();i++)
    {
        Mat temp = Mat(src.rows,src.cols,CV_8UC1,Scalar(255));
        LabelImages.push_back(temp);
        temp.release();
    }

    LabelImageInOne = Mat(src.rows,src.cols,CV_8UC1,Scalar(255));

    for(int i=0;i<Labels.size();i++)
    {
        for(int j=0;j<3;j++)
        {
            LabelColor[i][j] = rng.uniform(0, 255);
        }
    }
    



    this->close();
    LabelProcessingBlocks LPB;
    LPB.setModal(true);
    LPB.exec();
}
