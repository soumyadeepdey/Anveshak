#ifndef UPDATELABELASKING_H
#define UPDATELABELASKING_H

#include <QDialog>

namespace Ui {
class UpdateLabelAsking;
}

class UpdateLabelAsking : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateLabelAsking(QWidget *parent = 0);
    ~UpdateLabelAsking();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::UpdateLabelAsking *ui;
};

#endif // UPDATELABELASKING_H
