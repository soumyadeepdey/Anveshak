/********************************************************************************
** Form generated from reading UI file 'continue.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTINUE_H
#define UI_CONTINUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Continue
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Continue)
    {
        if (Continue->objectName().isEmpty())
            Continue->setObjectName(QStringLiteral("Continue"));
        Continue->resize(266, 172);
        label = new QLabel(Continue);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 40, 61, 21));
        pushButton = new QPushButton(Continue);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 80, 81, 22));
        pushButton_2 = new QPushButton(Continue);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(130, 80, 81, 21));

        retranslateUi(Continue);

        QMetaObject::connectSlotsByName(Continue);
    } // setupUi

    void retranslateUi(QDialog *Continue)
    {
        Continue->setWindowTitle(QApplication::translate("Continue", "Dialog", 0));
        label->setText(QApplication::translate("Continue", "continue", 0));
        pushButton->setText(QApplication::translate("Continue", "Yes", 0));
        pushButton_2->setText(QApplication::translate("Continue", "No", 0));
    } // retranslateUi

};

namespace Ui {
    class Continue: public Ui_Continue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTINUE_H
