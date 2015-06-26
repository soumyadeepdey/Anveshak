#ifndef LABELROI_H
#define LABELROI_H

#include <QDialog>

namespace Ui {
class LabelROI;
}

class LabelROI : public QDialog
{
    Q_OBJECT

public:
    explicit LabelROI(QWidget *parent = 0);
    ~LabelROI();

private slots:
    void on_pushButton_clicked();

private:
    Ui::LabelROI *ui;
};

#endif // LABELROI_H
