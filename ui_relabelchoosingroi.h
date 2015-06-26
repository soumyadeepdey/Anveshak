/********************************************************************************
** Form generated from reading UI file 'relabelchoosingroi.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RELABELCHOOSINGROI_H
#define UI_RELABELCHOOSINGROI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ReLabelChoosingROI
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *ReLabelChoosingROI)
    {
        if (ReLabelChoosingROI->objectName().isEmpty())
            ReLabelChoosingROI->setObjectName(QStringLiteral("ReLabelChoosingROI"));
        ReLabelChoosingROI->resize(391, 292);
        pushButton = new QPushButton(ReLabelChoosingROI);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(70, 70, 241, 51));
        pushButton_2 = new QPushButton(ReLabelChoosingROI);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(130, 190, 111, 41));

        retranslateUi(ReLabelChoosingROI);

        QMetaObject::connectSlotsByName(ReLabelChoosingROI);
    } // setupUi

    void retranslateUi(QDialog *ReLabelChoosingROI)
    {
        ReLabelChoosingROI->setWindowTitle(QApplication::translate("ReLabelChoosingROI", "Dialog", 0));
        pushButton->setText(QApplication::translate("ReLabelChoosingROI", "Re-Label By Selecting ROI", 0));
        pushButton_2->setText(QApplication::translate("ReLabelChoosingROI", "Finalize Labeling", 0));
    } // retranslateUi

};

namespace Ui {
    class ReLabelChoosingROI: public Ui_ReLabelChoosingROI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RELABELCHOOSINGROI_H
