/********************************************************************************
** Form generated from reading UI file 'labelprocessingblocks.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LABELPROCESSINGBLOCKS_H
#define UI_LABELPROCESSINGBLOCKS_H

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

class Ui_LabelProcessingBlocks
{
public:
    QLabel *label;
    QGroupBox *groupBox;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *LabelProcessingBlocks)
    {
        if (LabelProcessingBlocks->objectName().isEmpty())
            LabelProcessingBlocks->setObjectName(QStringLiteral("LabelProcessingBlocks"));
        LabelProcessingBlocks->resize(568, 382);
        label = new QLabel(LabelProcessingBlocks);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 10, 331, 31));
        QFont font;
        font.setFamily(QStringLiteral("URW Bookman L"));
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(50);
        label->setFont(font);
        groupBox = new QGroupBox(LabelProcessingBlocks);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(80, 80, 391, 161));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(20, 40, 221, 20));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(20, 100, 211, 21));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(290, 70, 81, 22));
        pushButton_2 = new QPushButton(LabelProcessingBlocks);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 290, 81, 22));

        retranslateUi(LabelProcessingBlocks);

        QMetaObject::connectSlotsByName(LabelProcessingBlocks);
    } // setupUi

    void retranslateUi(QDialog *LabelProcessingBlocks)
    {
        LabelProcessingBlocks->setWindowTitle(QApplication::translate("LabelProcessingBlocks", "Dialog", 0));
        label->setText(QApplication::translate("LabelProcessingBlocks", "Label Processing Blocks", 0));
        groupBox->setTitle(QApplication::translate("LabelProcessingBlocks", "GroupBox", 0));
        radioButton->setText(QApplication::translate("LabelProcessingBlocks", "Label Individual Unlabbeled PB", 0));
        radioButton_2->setText(QApplication::translate("LabelProcessingBlocks", "Label PB by Selecting a ROI", 0));
        pushButton->setText(QApplication::translate("LabelProcessingBlocks", "select", 0));
        pushButton_2->setText(QApplication::translate("LabelProcessingBlocks", "Done", 0));
    } // retranslateUi

};

namespace Ui {
    class LabelProcessingBlocks: public Ui_LabelProcessingBlocks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABELPROCESSINGBLOCKS_H
