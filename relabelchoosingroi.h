#ifndef RELABELCHOOSINGROI_H
#define RELABELCHOOSINGROI_H

#include <QDialog>

namespace Ui {
class ReLabelChoosingROI;
}

class ReLabelChoosingROI : public QDialog
{
    Q_OBJECT

public:
    explicit ReLabelChoosingROI(QWidget *parent = 0);
    ~ReLabelChoosingROI();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::ReLabelChoosingROI *ui;
};

#endif // RELABELCHOOSINGROI_H
