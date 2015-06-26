#ifndef WANTTORELABELROI_H
#define WANTTORELABELROI_H

#include <QDialog>

namespace Ui {
class WantToRelabelROI;
}

class WantToRelabelROI : public QDialog
{
    Q_OBJECT

public:
    explicit WantToRelabelROI(QWidget *parent = 0);
    ~WantToRelabelROI();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::WantToRelabelROI *ui;
};

#endif // WANTTORELABELROI_H
