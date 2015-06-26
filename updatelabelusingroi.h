#ifndef UPDATELABELUSINGROI_H
#define UPDATELABELUSINGROI_H

#include <QDialog>

namespace Ui {
class UpdateLabelUsingROI;
}

class UpdateLabelUsingROI : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateLabelUsingROI(QWidget *parent = 0);
    ~UpdateLabelUsingROI();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::UpdateLabelUsingROI *ui;
};

#endif // UPDATELABELUSINGROI_H
