#ifndef CONTINUELABELING_H
#define CONTINUELABELING_H

#include <QDialog>

namespace Ui {
class continuelabeling;
}

class continuelabeling : public QDialog
{
    Q_OBJECT

public:
    explicit continuelabeling(QWidget *parent = 0);
    ~continuelabeling();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::continuelabeling *ui;
};

#endif // CONTINUELABELING_H
