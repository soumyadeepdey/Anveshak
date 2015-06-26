#include "chagelabelofpbs.h"
#include "ui_chagelabelofpbs.h"
#include "myheader.h"
#include "QMessageBox"
#include "updatelabelusingroi.h"

IITkgp_functions::folder fol;

ChageLabelofPBs::ChageLabelofPBs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChageLabelofPBs)
{
    ui->setupUi(this);
}

ChageLabelofPBs::~ChageLabelofPBs()
{
    delete ui;
}

void ChageLabelofPBs::on_pushButton_clicked() //Yes
{
    UpdateLabelUsingROI ULUR;
    this->close();
    ULUR.setModal(true);
    ULUR.exec();

}



void ChageLabelofPBs::on_pushButton_2_clicked() //NO
{
 
    
    this->close();
    QMessageBox::information(0,"Labelling","Labelling of All Processing block are done");

    for(int i=0;i<Labels.size();i++)
    {
       // string s = Labels[i].toUtf8().constData();
      //  char * name;
      //  name = fol.CreateNameIntoFolder(substring,s.c_str());
      //  fol.makedir(name);
        
        char *out;
        int sp;
        sp = sprintf(out,"_Label%d.png",i);
        char *cp = substring;
        strcat(cp,out);
        char * name;
        name = fol.CreateNameIntoFolder(substring,cp);
        imwrite(name,LabelImages[i]);
        
    }
    LabelImages.clear();

    char *cp = substring;
    strcat(cp,"_AllInOneLabel.png");
    char * name;
    name = fol.CreateNameIntoFolder(substring,cp);
    imwrite(name,LabelImageInOne);
    LabelImageInOne.release();

    src.release();
    src_binary.release();
    src_ub.release();
    src_ROI.release();

    name = (char *) malloc(2000*sizeof(char));
    name = fol.CreateNameIntoFolder(substring,"ColorAllInOneLabel.png");
    imwrite(name,ColorLabelImage);
    ColorLabelImage.release();

    free(LabelFlag);
    free(PBLabel);

    for(int i=0;i<Labels.size();i++)
    {
        free(LabelColor[i]);
    }
    free(LabelColor);

    contours.clear();
    hierarchy.clear();


    

}

