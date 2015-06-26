/********************************************************************************
** Form generated from reading UI file 'binary.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BINARY_H
#define UI_BINARY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Binary
{
public:
    QGroupBox *groupBox;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *Binary)
    {
        if (Binary->objectName().isEmpty())
            Binary->setObjectName(QStringLiteral("Binary"));
        Binary->resize(400, 300);
        groupBox = new QGroupBox(Binary);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(60, 20, 271, 161));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(20, 50, 102, 20));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(150, 50, 102, 20));
        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(100, 80, 51, 21));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 20, 151, 21));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 110, 81, 22));

        retranslateUi(Binary);

        QMetaObject::connectSlotsByName(Binary);
    } // setupUi

    void retranslateUi(QDialog *Binary)
    {
        Binary->setWindowTitle(QApplication::translate("Binary", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("Binary", "Binarization Selection", 0));
        radioButton->setText(QApplication::translate("Binary", "Adaptive", 0));
        radioButton_2->setText(QApplication::translate("Binary", "Otsu", 0));
        radioButton_3->setText(QApplication::translate("Binary", "GUI", 0));
        label->setText(QApplication::translate("Binary", "Select Binarization Type", 0));
        pushButton->setText(QApplication::translate("Binary", "select", 0));
    } // retranslateUi

};

namespace Ui {
    class Binary: public Ui_Binary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BINARY_H
