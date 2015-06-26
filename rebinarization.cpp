#include "rebinarization.h"
#include "ui_rebinarization.h"
#include "binary.h"
#include "myheader.h"
#include "preprocessingblock.h"

ReBinarization::ReBinarization(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReBinarization)
{
    ui->setupUi(this);
}

ReBinarization::~ReBinarization()
{
    delete ui;
}

void ReBinarization::on_pushButton_clicked() // if select yes
{
    destroyWindow("Binary Image");
    destroyWindow("Original Image");
    destroyWindow("Uniform Background Image");
    Binary BSelecWin;
    BSelecWin.setModal(true);
    BSelecWin.exec();
    this->close();
}

void ReBinarization::on_pushButton_2_clicked() // if select no
{
    destroyWindow("Binary Image");
    destroyWindow("Original Image");
    destroyWindow("Uniform Background Image");
    IITkgp_functions::folder folderobj;
    /*
    char *name;
    name = (char *) malloc ( 2001 * sizeof(char));
      if(name == NULL)
      {
        printf("Memory can not be allocated\n");
        exit(0);
      }
      name = folderobj.CreateNameIntoFolder(substring,"binary.png");
      imwrite(name,src_binary);


      name = (char *) malloc ( 2001 * sizeof(char));
        if(name == NULL)
        {
          printf("Memory can not be allocated\n");
          exit(0);
        }
        name = folderobj.CreateNameIntoFolder(substring,"UniformBackground.png");
        imwrite(name,src_ub);
        */

        this->close();

        src_binary.copyTo(ResultImage);

        PreProcessingBlock PPB;
        PPB.setModal(true);
        PPB.exec();


}
