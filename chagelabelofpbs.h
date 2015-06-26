#ifndef CHAGELABELOFPBS_H
#define CHAGELABELOFPBS_H

#include <QDialog>

namespace Ui {
class ChageLabelofPBs;
}

class ChageLabelofPBs : public QDialog
{
    Q_OBJECT

public:
    explicit ChageLabelofPBs(QWidget *parent = 0);
    ~ChageLabelofPBs();

private slots:
    void on_pushButton_clicked();

    
    void on_pushButton_2_clicked();
    
private:
    Ui::ChageLabelofPBs *ui;
};

#endif // CHAGELABELOFPBS_H
