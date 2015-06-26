#include "binary.h"
#include "ui_binary.h"
#include "myheader.h"
#include "QMessageBox"
#include "rebinarization.h"

Binary::Binary(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Binary)
{
    ui->setupUi(this);
}

Binary::~Binary()
{
    delete ui;
}
Mat ResultImage;
void Binary::on_pushButton_clicked()
{
    int BinarizationType;
    if(ui->radioButton->isChecked()) // adaptive
    {
        destroyWindow("Src Image");
        QMessageBox::information(0,"Binarization","Adaptive Binarization is selected");
        BinarizationType = 1;
    }
    else if(ui->radioButton_2->isChecked()) // otsu
    {
        destroyWindow("Src Image");
        QMessageBox::information(0,"Binarization","Otsu's Binarization is selected");
        BinarizationType = 2;
    }
    else if(ui->radioButton_3->isChecked()) // GUI
    {
        destroyWindow("Src Image");
        QMessageBox::information(0,"Binarization","Binarization with user interface is selected");
        BinarizationType = 3;
    }
    Mat BinaryImage;
    IITkgp_functions::BinaryImage Bproc;
    BinaryImage = Bproc.binarization(src,BinarizationType);
    namedWindow( "Binary Image", CV_WINDOW_KEEPRATIO );
    imshow("Binary Image",BinaryImage);


    //BinaryImage.copyTo(src_binary);

    Mat UniformBackImage;
    IITkgp_functions::ImageProcFunc Iproc;
    UniformBackImage = Iproc.foreground_masked_image(src,BinaryImage);
    namedWindow( "Uniform Background Image", CV_WINDOW_KEEPRATIO );
    namedWindow( "Original Image", CV_WINDOW_KEEPRATIO );
    imshow("Original Image", src);
    imshow("Uniform Background Image",UniformBackImage);

    //waitKey(0);

    BinaryImage.copyTo(src_binary);
    BinaryImage.copyTo(ResultImage);
    BinaryImage.release();
    UniformBackImage.copyTo(src_ub);
    UniformBackImage.release();
    this->close();

    ReBinarization REB;
    REB.setModal(true);
    REB.exec();


}
