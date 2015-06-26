#ifndef CUSTOMIZELABELS_H
#define CUSTOMIZELABELS_H

#include <QDialog>

namespace Ui {
class CustomizeLabels;
}

class CustomizeLabels : public QDialog
{
    Q_OBJECT

public:
    explicit CustomizeLabels(QWidget *parent = 0);
    ~CustomizeLabels();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::CustomizeLabels *ui;
};

#endif // CUSTOMIZELABELS_H
