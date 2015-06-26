/********************************************************************************
** Form generated from reading UI file 'selectlabel.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTLABEL_H
#define UI_SELECTLABEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SelectLabel
{
public:
    QComboBox *comboBox;
    QPushButton *pushButton;

    void setupUi(QDialog *SelectLabel)
    {
        if (SelectLabel->objectName().isEmpty())
            SelectLabel->setObjectName(QStringLiteral("SelectLabel"));
        SelectLabel->resize(240, 111);
        comboBox = new QComboBox(SelectLabel);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(20, 40, 101, 22));
        pushButton = new QPushButton(SelectLabel);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 40, 71, 21));

        retranslateUi(SelectLabel);

        QMetaObject::connectSlotsByName(SelectLabel);
    } // setupUi

    void retranslateUi(QDialog *SelectLabel)
    {
        SelectLabel->setWindowTitle(QApplication::translate("SelectLabel", "Dialog", 0));
        pushButton->setText(QApplication::translate("SelectLabel", "select", 0));
    } // retranslateUi

};

namespace Ui {
    class SelectLabel: public Ui_SelectLabel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTLABEL_H
