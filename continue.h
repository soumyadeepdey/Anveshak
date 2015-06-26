#ifndef CONTINUE_H
#define CONTINUE_H

#include <QDialog>

namespace Ui {
class Continue;
}

class Continue : public QDialog
{
    Q_OBJECT

public:
    explicit Continue(QWidget *parent = 0);
    ~Continue();

private slots:
    void on_pushButton_clicked();

    
    void on_pushButton_2_clicked();
    
private:
    Ui::Continue *ui;
};

#endif // CONTINUE_H
