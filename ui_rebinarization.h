/********************************************************************************
** Form generated from reading UI file 'rebinarization.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REBINARIZATION_H
#define UI_REBINARIZATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ReBinarization
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *ReBinarization)
    {
        if (ReBinarization->objectName().isEmpty())
            ReBinarization->setObjectName(QStringLiteral("ReBinarization"));
        ReBinarization->resize(139, 90);
        label = new QLabel(ReBinarization);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 91, 16));
        pushButton = new QPushButton(ReBinarization);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 50, 31, 16));
        pushButton_2 = new QPushButton(ReBinarization);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(80, 50, 31, 16));

        retranslateUi(ReBinarization);

        QMetaObject::connectSlotsByName(ReBinarization);
    } // setupUi

    void retranslateUi(QDialog *ReBinarization)
    {
        ReBinarization->setWindowTitle(QApplication::translate("ReBinarization", "Dialog", 0));
        label->setText(QApplication::translate("ReBinarization", "Binarize Again", 0));
        pushButton->setText(QApplication::translate("ReBinarization", "Yes", 0));
        pushButton_2->setText(QApplication::translate("ReBinarization", "No", 0));
    } // retranslateUi

};

namespace Ui {
    class ReBinarization: public Ui_ReBinarization {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REBINARIZATION_H
