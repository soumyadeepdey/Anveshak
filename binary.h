#ifndef BINARY_H
#define BINARY_H

#include <QDialog>

namespace Ui {
class Binary;
}

class Binary : public QDialog
{
    Q_OBJECT

public:
    explicit Binary(QWidget *parent = 0);
    ~Binary();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Binary *ui;
};

#endif // BINARY_H
