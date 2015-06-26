#include "myheader.h"
#include "groundtruth.h"
#include "ui_groundtruth.h"

int radiobottonnum;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GroundTruth w;
    w.show();

    return a.exec();
}
