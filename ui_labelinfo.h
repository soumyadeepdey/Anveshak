/********************************************************************************
** Form generated from reading UI file 'labelinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LABELINFO_H
#define UI_LABELINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LabelInfo
{
public:
    QComboBox *comboBox;
    QPushButton *pushButton_2;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *LabelInfo)
    {
        if (LabelInfo->objectName().isEmpty())
            LabelInfo->setObjectName(QStringLiteral("LabelInfo"));
        LabelInfo->resize(242, 166);
        comboBox = new QComboBox(LabelInfo);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(130, 30, 72, 22));
        pushButton_2 = new QPushButton(LabelInfo);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(130, 100, 81, 22));
        label = new QLabel(LabelInfo);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 41, 16));
        pushButton = new QPushButton(LabelInfo);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 100, 81, 22));

        retranslateUi(LabelInfo);

        QMetaObject::connectSlotsByName(LabelInfo);
    } // setupUi

    void retranslateUi(QDialog *LabelInfo)
    {
        LabelInfo->setWindowTitle(QApplication::translate("LabelInfo", "Dialog", 0));
        pushButton_2->setText(QApplication::translate("LabelInfo", "Customize", 0));
        label->setText(QApplication::translate("LabelInfo", "Labels", 0));
        pushButton->setText(QApplication::translate("LabelInfo", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class LabelInfo: public Ui_LabelInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABELINFO_H
