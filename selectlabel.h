#ifndef SELECTLABEL_H
#define SELECTLABEL_H

#include <QDialog>

namespace Ui {
class SelectLabel;
}

class SelectLabel : public QDialog
{
    Q_OBJECT

public:
    explicit SelectLabel(QWidget *parent = 0);
    ~SelectLabel();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SelectLabel *ui;
};

#endif // SELECTLABEL_H
