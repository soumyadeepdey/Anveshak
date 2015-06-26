/********************************************************************************
** Form generated from reading UI file 'customizelabels.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMIZELABELS_H
#define UI_CUSTOMIZELABELS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CustomizeLabels
{
public:
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *CustomizeLabels)
    {
        if (CustomizeLabels->objectName().isEmpty())
            CustomizeLabels->setObjectName(QStringLiteral("CustomizeLabels"));
        CustomizeLabels->resize(344, 191);
        lineEdit = new QLineEdit(CustomizeLabels);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(20, 20, 113, 22));
        comboBox = new QComboBox(CustomizeLabels);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(210, 20, 111, 22));
        pushButton = new QPushButton(CustomizeLabels);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 90, 91, 22));
        pushButton_2 = new QPushButton(CustomizeLabels);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 90, 91, 21));
        pushButton_3 = new QPushButton(CustomizeLabels);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(130, 150, 81, 22));

        retranslateUi(CustomizeLabels);

        QMetaObject::connectSlotsByName(CustomizeLabels);
    } // setupUi

    void retranslateUi(QDialog *CustomizeLabels)
    {
        CustomizeLabels->setWindowTitle(QApplication::translate("CustomizeLabels", "Dialog", 0));
        pushButton->setText(QApplication::translate("CustomizeLabels", "Add Label", 0));
        pushButton_2->setText(QApplication::translate("CustomizeLabels", "Delete Label", 0));
        pushButton_3->setText(QApplication::translate("CustomizeLabels", "Done", 0));
    } // retranslateUi

};

namespace Ui {
    class CustomizeLabels: public Ui_CustomizeLabels {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMIZELABELS_H
