#ifndef GROUNDTRUTH_H
#define GROUNDTRUTH_H

#include <QMainWindow>




namespace Ui {
class GroundTruth;
}

class GroundTruth : public QMainWindow
{
    Q_OBJECT

public:
    explicit GroundTruth(QWidget *parent = 0);
    ~GroundTruth();

private slots:
    void on_pushButton_clicked();

private:
    Ui::GroundTruth *ui;
};

#endif // GROUNDTRUTH_H
