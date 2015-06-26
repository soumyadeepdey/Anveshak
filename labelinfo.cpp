#include "labelinfo.h"
#include "ui_labelinfo.h"
#include "myheader.h"
#include "customizelabels.h"
#include "labelprocessingblocks.h"

bool cflag = false;
char *tempname;

LabelInfo::LabelInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LabelInfo)
{
    ui->setupUi(this);



    for(int i=0;i<Labels.size();i++)
        ui->comboBox->addItem(Labels[i]);
}



LabelInfo::~LabelInfo()
{
    delete ui;

}


int *(*LabelColor);
int *LabelCount;
vector<Mat> LabelImages;
Mat LabelImageInOne;

RNG rng(12345);

void LabelInfo::on_pushButton_clicked() // OK
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
        for(int j=0;j<3;j++)
        {
            LabelColor[i][j] = rng.uniform(0, 255);
        }
    }
    
    for(int i=0;i<Labels.size();i++)
    {
        Mat temp = Mat(src.rows,src.cols,CV_8UC1,Scalar(255));
        LabelImages.push_back(temp);
        temp.release();
    }

    LabelImageInOne = Mat(src.rows,src.cols,CV_8UC1,Scalar(255));

    this->close();
    
    LabelProcessingBlocks LPB;
    LPB.setModal(true);
    LPB.exec();


}





void LabelInfo::on_pushButton_2_clicked() // Customized Label
{
    this->close();

    CustomizeLabels CL;
    CL.setModal(true);
    CL.exec();


}
