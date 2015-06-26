#ifndef LABELPROCESSINGBLOCKS_H
#define LABELPROCESSINGBLOCKS_H

#include <QDialog>

namespace Ui {
class LabelProcessingBlocks;
}

class LabelProcessingBlocks : public QDialog
{
    Q_OBJECT

public:
    explicit LabelProcessingBlocks(QWidget *parent = 0);
    ~LabelProcessingBlocks();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::LabelProcessingBlocks *ui;
};

#endif // LABELPROCESSINGBLOCKS_H
