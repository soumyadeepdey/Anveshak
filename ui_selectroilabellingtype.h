/********************************************************************************
** Form generated from reading UI file 'selectroilabellingtype.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTROILABELLINGTYPE_H
#define UI_SELECTROILABELLINGTYPE_H

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

class Ui_SelectROILabellingType
{
public:
    QGroupBox *groupBox;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *SelectROILabellingType)
    {
        if (SelectROILabellingType->objectName().isEmpty())
            SelectROILabellingType->setObjectName(QStringLiteral("SelectROILabellingType"));
        SelectROILabellingType->resize(712, 434);
        groupBox = new QGroupBox(SelectROILabellingType);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(90, 70, 531, 261));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(30, 40, 381, 21));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(30, 80, 441, 21));
        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(30, 120, 421, 31));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(230, 190, 81, 22));
        label = new QLabel(SelectROILabellingType);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 20, 571, 21));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);

        retranslateUi(SelectROILabellingType);

        QMetaObject::connectSlotsByName(SelectROILabellingType);
    } // setupUi

    void retranslateUi(QDialog *SelectROILabellingType)
    {
        SelectROILabellingType->setWindowTitle(QApplication::translate("SelectROILabellingType", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("SelectROILabellingType", "GroupBox", 0));
        radioButton->setText(QApplication::translate("SelectROILabellingType", "Change Label of all PB within ROI with a particular Label", 0));
        radioButton_2->setText(QApplication::translate("SelectROILabellingType", "Change Label of all unlabelled PB within ROI with a particular Label", 0));
        radioButton_3->setText(QApplication::translate("SelectROILabellingType", "Select Label for Individual PB Within ROI", 0));
        pushButton->setText(QApplication::translate("SelectROILabellingType", "select", 0));
        label->setText(QApplication::translate("SelectROILabellingType", "Select Labeling Type For Labelling PB Within A ROI", 0));
    } // retranslateUi

};

namespace Ui {
    class SelectROILabellingType: public Ui_SelectROILabellingType {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTROILABELLINGTYPE_H
