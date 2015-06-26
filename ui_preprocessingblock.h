/********************************************************************************
** Form generated from reading UI file 'preprocessingblock.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREPROCESSINGBLOCK_H
#define UI_PREPROCESSINGBLOCK_H

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

class Ui_PreProcessingBlock
{
public:
    QGroupBox *groupBox;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_2;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QPushButton *pushButton_4;

    void setupUi(QDialog *PreProcessingBlock)
    {
        if (PreProcessingBlock->objectName().isEmpty())
            PreProcessingBlock->setObjectName(QStringLiteral("PreProcessingBlock"));
        PreProcessingBlock->resize(565, 323);
        groupBox = new QGroupBox(PreProcessingBlock);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 40, 241, 141));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(30, 40, 102, 20));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(150, 40, 102, 20));
        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(30, 80, 102, 20));
        radioButton_4 = new QRadioButton(groupBox);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setGeometry(QRect(150, 80, 102, 20));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 110, 81, 22));
        label = new QLabel(PreProcessingBlock);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(200, 10, 161, 21));
        pushButton_2 = new QPushButton(PreProcessingBlock);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(230, 270, 81, 22));
        groupBox_2 = new QGroupBox(PreProcessingBlock);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(300, 40, 231, 141));
        radioButton_5 = new QRadioButton(groupBox_2);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        radioButton_5->setGeometry(QRect(10, 30, 102, 20));
        radioButton_6 = new QRadioButton(groupBox_2);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));
        radioButton_6->setGeometry(QRect(120, 30, 102, 20));
        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(70, 100, 81, 22));

        retranslateUi(PreProcessingBlock);

        QMetaObject::connectSlotsByName(PreProcessingBlock);
    } // setupUi

    void retranslateUi(QDialog *PreProcessingBlock)
    {
        PreProcessingBlock->setWindowTitle(QApplication::translate("PreProcessingBlock", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("PreProcessingBlock", "Morphological Operations", 0));
        radioButton->setText(QApplication::translate("PreProcessingBlock", "Erode", 0));
        radioButton_2->setText(QApplication::translate("PreProcessingBlock", "Dilate", 0));
        radioButton_3->setText(QApplication::translate("PreProcessingBlock", "Open", 0));
        radioButton_4->setText(QApplication::translate("PreProcessingBlock", "Close", 0));
        pushButton->setText(QApplication::translate("PreProcessingBlock", "select", 0));
        label->setText(QApplication::translate("PreProcessingBlock", "Create Processing Block", 0));
        pushButton_2->setText(QApplication::translate("PreProcessingBlock", "Done", 0));
        groupBox_2->setTitle(QApplication::translate("PreProcessingBlock", "Smoothing or Gapfilling Operation", 0));
        radioButton_5->setText(QApplication::translate("PreProcessingBlock", "Smoothing", 0));
        radioButton_6->setText(QApplication::translate("PreProcessingBlock", "Gapfilling", 0));
        pushButton_4->setText(QApplication::translate("PreProcessingBlock", "select", 0));
    } // retranslateUi

};

namespace Ui {
    class PreProcessingBlock: public Ui_PreProcessingBlock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREPROCESSINGBLOCK_H
