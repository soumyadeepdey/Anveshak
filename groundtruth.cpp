#include "myheader.h"
#include "groundtruth.h"
#include "ui_groundtruth.h"
#include "QFileDialog"
#include "binary.h"


vector<QString> Labels;

GroundTruth::GroundTruth(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GroundTruth)
{
    ui->setupUi(this);

    Labels.push_back("Text");
    Labels.push_back("Bold Text");
    Labels.push_back("Graphics");
    Labels.push_back("Logo");
    Labels.push_back("Stamp");
    Labels.push_back("Headers");
    Labels.push_back("Head Line");
    Labels.push_back("Signature");
    Labels.push_back("Noise");
}

GroundTruth::~GroundTruth()
{
    delete ui;
}

Mat src,src_gray,src_binary,src_ROI,src_ub;
char *substring;
const char *imagename;
void GroundTruth::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "/home/soumyadeep/work/stampVarOwnData/soumya/non_overlapped/",
                "All Files (*.*)" );
    string imagepath;
    imagepath = filename.toUtf8().constData();
    src = imread(imagepath,1);


    cvtColor(src, src_gray, CV_BGR2GRAY);

    //IITkgp_functions::statistical_analysis stat;
    //stat.DrawHistogram(src_gray);


    IITkgp_functions::folder folderobj;

    imagename = imagepath.c_str();
    substring = folderobj.input_image_name_cut(imagepath.c_str());
    folderobj.makedir(substring);

    /*
    char *name;
    name = (char *) malloc ( 2001 * sizeof(char));
      if(name == NULL)
      {
        printf("Memory can not be allocated\n");
        exit(0);
      }
      name = folderobj.CreateNameIntoFolder(substring,"gray.png");
      imwrite(name,src_gray);
      */

      namedWindow( "Src Image", CV_WINDOW_KEEPRATIO );
      imshow("Src Image",src);


      Binary BSelecWin;
      BSelecWin.setModal(true);
      BSelecWin.exec();
      //waitKey(0);
}
