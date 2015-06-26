#ifndef UNDOPREPROCESSING_H
#define UNDOPREPROCESSING_H

#include <QDialog>

namespace Ui {
class UndoPreprocessing;
}

class UndoPreprocessing : public QDialog
{
    Q_OBJECT

public:
    explicit UndoPreprocessing(QWidget *parent = 0);
    ~UndoPreprocessing();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::UndoPreprocessing *ui;
};

#endif // UNDOPREPROCESSING_H
