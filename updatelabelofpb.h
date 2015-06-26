#ifndef UPDATELABELOFPB_H
#define UPDATELABELOFPB_H

#include <QDialog>

namespace Ui {
class UpdateLabelofPB;
}

class UpdateLabelofPB : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateLabelofPB(QWidget *parent = 0);
    ~UpdateLabelofPB();

private slots:
    void on_pushButton_clicked();

    
    void on_pushButton_2_clicked();
    
private:
    Ui::UpdateLabelofPB *ui;
};

#endif // UPDATELABELOFPB_H
