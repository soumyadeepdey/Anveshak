#ifndef PREPROCESSINGBLOCK_H
#define PREPROCESSINGBLOCK_H

#include <QDialog>

namespace Ui {
class PreProcessingBlock;
}

class PreProcessingBlock : public QDialog
{
    Q_OBJECT

public:
    explicit PreProcessingBlock(QWidget *parent = 0);
    ~PreProcessingBlock();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::PreProcessingBlock *ui;
};

#endif // PREPROCESSINGBLOCK_H
