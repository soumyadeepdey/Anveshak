#ifndef LABELINFO_H
#define LABELINFO_H

#include <QDialog>

namespace Ui {
class LabelInfo;
}

class LabelInfo : public QDialog
{
    Q_OBJECT

public:
    explicit LabelInfo(QWidget *parent = 0);
    ~LabelInfo();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::LabelInfo *ui;
};

#endif // LABELINFO_H
