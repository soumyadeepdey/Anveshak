#include "updatelabelusingroi.h"
#include "ui_updatelabelusingroi.h"
#include "myheader.h"
#include "labelroi.h"
#include "updatelabelofpb.h"
#include "QMessageBox"
#include "continue.h"
#include "chagelabelofpbs.h"

UpdateLabelUsingROI::UpdateLabelUsingROI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateLabelUsingROI)
{
    ui->setupUi(this);
}

UpdateLabelUsingROI::~UpdateLabelUsingROI()
{
    delete ui;
}

void UpdateLabelUsingROI::on_pushButton_clicked() // ROI
{

    IITkgp_functions::ProcessingBlocks PB;
    IITkgp_functions::RectangleTest RT;
    LabelROI LR;
    UpdateLabelofPB ULPB;

    Rect temproi = PB.SelectROI(ColorLabelImage);
    tempname = "selected roi";
    namedWindow(tempname,CV_WINDOW_KEEPRATIO);
    imshow(tempname,src_ub(temproi));

    LR.setModal(true);
    LR.exec();

    int k = 0;
    for(int i=0;i<contours.size();i++)
    {
        if(hierarchy[i][3] == -1)
        {
            vector<Point> contours_poly;
            Rect BoundRect;
            approxPolyDP( Mat(contours[i]), contours_poly, 3, true );
            BoundRect = boundingRect( Mat(contours_poly) );
            if(RT.FindOverlappingRectangles(temproi,BoundRect) == 2);
            {
                if(PBLabel[k] != selectedlabel)
                {
                    cflag = false;
                    QMessageBox::information(0,"Labelling","Labelling of Processing block is "+Labels[k]);
                    namedWindow("PB",CV_WINDOW_KEEPRATIO);
                    imshow("PB",Blocks[k]);
                    ULPB.setModal(true);
                    ULPB.exec();
                    if(cflag)   // if label of PB changed
                    {
                        LabelCount[PBLabel[k]] = LabelCount[PBLabel[k]] - 1;
                        LabelCount[selectedlabel] = LabelCount[selectedlabel] + 1;
                        for(int m=BoundRect.y;m<BoundRect.y+BoundRect.height;m++)
                        {

                            for(int n=BoundRect.x;n<BoundRect.x+BoundRect.width;n++)
                            {
                                bool measure_dist;
                                if((pointPolygonTest(contours_poly,Point(n,m),measure_dist) > 0.0) && src_binary.data[m*src_binary.cols+n]==0)
                                {
                                    LabelImages[PBLabel[k]].data[m*ColorLabelImage.cols+n] = 255;
                                    LabelImages[selectedlabel].data[m*ColorLabelImage.cols+n] = 0;
                                    ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+0] = LabelColor[selectedlabel][0];
                                    ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+1] = LabelColor[selectedlabel][1];
                                    ColorLabelImage.data[(m*ColorLabelImage.cols+n)*3+2] = LabelColor[selectedlabel][2];
                                }
                            }
                        }
                        PBLabel[k] = selectedlabel;
                        QMessageBox::information(0,"Labelling","Labelling of Processing block is updated to "+Labels[selectedlabel]);

                    }
                    destroyWindow("PB");

                }
            }
            k = k + 1;
        }
    }

    Continue CN;
    CN.setModal(true);
    CN.exec();

    if(cflag)
    {
        this->close();
        destroyWindow(tempname);
        UpdateLabelUsingROI ULUR;
        ULUR.setModal(true);
        ULUR.exec();
    }
    else
    {
        this->close();
        destroyWindow(tempname);
    }

}

void UpdateLabelUsingROI::on_pushButton_2_clicked() // DONE
{
    IITkgp_functions::folder fol;

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


    name = (char *)malloc(2000*sizeof(char));
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
