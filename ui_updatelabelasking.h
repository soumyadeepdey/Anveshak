/********************************************************************************
** Form generated from reading UI file 'updatelabelasking.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATELABELASKING_H
#define UI_UPDATELABELASKING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_UpdateLabelAsking
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *UpdateLabelAsking)
    {
        if (UpdateLabelAsking->objectName().isEmpty())
            UpdateLabelAsking->setObjectName(QStringLiteral("UpdateLabelAsking"));
        UpdateLabelAsking->resize(302, 169);
        label = new QLabel(UpdateLabelAsking);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 40, 211, 21));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        pushButton = new QPushButton(UpdateLabelAsking);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 100, 81, 22));
        pushButton_2 = new QPushButton(UpdateLabelAsking);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(190, 100, 81, 22));

        retranslateUi(UpdateLabelAsking);

        QMetaObject::connectSlotsByName(UpdateLabelAsking);
    } // setupUi

    void retranslateUi(QDialog *UpdateLabelAsking)
    {
        UpdateLabelAsking->setWindowTitle(QApplication::translate("UpdateLabelAsking", "Dialog", 0));
        label->setText(QApplication::translate("UpdateLabelAsking", "Update Label of PB", 0));
        pushButton->setText(QApplication::translate("UpdateLabelAsking", "Yes", 0));
        pushButton_2->setText(QApplication::translate("UpdateLabelAsking", "No", 0));
    } // retranslateUi

};

namespace Ui {
    class UpdateLabelAsking: public Ui_UpdateLabelAsking {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATELABELASKING_H
