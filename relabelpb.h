#ifndef RELABELPB_H
#define RELABELPB_H

#include <QDialog>

namespace Ui {
class ReLabelPB;
}

class ReLabelPB : public QDialog
{
    Q_OBJECT

public:
    explicit ReLabelPB(QWidget *parent = 0);
    ~ReLabelPB();

private:
    Ui::ReLabelPB *ui;
};

#endif // RELABELPB_H
