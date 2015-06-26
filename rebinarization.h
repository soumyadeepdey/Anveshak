#ifndef REBINARIZATION_H
#define REBINARIZATION_H

#include <QDialog>

namespace Ui {
class ReBinarization;
}

class ReBinarization : public QDialog
{
    Q_OBJECT

public:
    explicit ReBinarization(QWidget *parent = 0);
    ~ReBinarization();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ReBinarization *ui;
};

#endif // REBINARIZATION_H
