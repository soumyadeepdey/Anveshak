#ifndef SELECTROILABELLINGTYPE_H
#define SELECTROILABELLINGTYPE_H

#include <QDialog>

namespace Ui {
class SelectROILabellingType;
}

class SelectROILabellingType : public QDialog
{
    Q_OBJECT

public:
    explicit SelectROILabellingType(QWidget *parent = 0);
    ~SelectROILabellingType();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SelectROILabellingType *ui;
};

#endif // SELECTROILABELLINGTYPE_H
