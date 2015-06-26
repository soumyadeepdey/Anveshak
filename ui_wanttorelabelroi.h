/********************************************************************************
** Form generated from reading UI file 'wanttorelabelroi.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WANTTORELABELROI_H
#define UI_WANTTORELABELROI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_WantToRelabelROI
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *WantToRelabelROI)
    {
        if (WantToRelabelROI->objectName().isEmpty())
            WantToRelabelROI->setObjectName(QStringLiteral("WantToRelabelROI"));
        WantToRelabelROI->resize(379, 222);
        label = new QLabel(WantToRelabelROI);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 40, 271, 41));
        QFont font;
        font.setFamily(QStringLiteral("Sans Serif"));
        font.setPointSize(14);
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(50);
        label->setFont(font);
        pushButton = new QPushButton(WantToRelabelROI);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 120, 91, 31));
        pushButton_2 = new QPushButton(WantToRelabelROI);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 120, 91, 31));

        retranslateUi(WantToRelabelROI);

        QMetaObject::connectSlotsByName(WantToRelabelROI);
    } // setupUi

    void retranslateUi(QDialog *WantToRelabelROI)
    {
        WantToRelabelROI->setWindowTitle(QApplication::translate("WantToRelabelROI", "Dialog", 0));
        label->setText(QApplication::translate("WantToRelabelROI", "Want To Re-Label Any ROI", 0));
        pushButton->setText(QApplication::translate("WantToRelabelROI", "Yes", 0));
        pushButton_2->setText(QApplication::translate("WantToRelabelROI", "No", 0));
    } // retranslateUi

};

namespace Ui {
    class WantToRelabelROI: public Ui_WantToRelabelROI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WANTTORELABELROI_H
