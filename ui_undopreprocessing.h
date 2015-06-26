/********************************************************************************
** Form generated from reading UI file 'undopreprocessing.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNDOPREPROCESSING_H
#define UI_UNDOPREPROCESSING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_UndoPreprocessing
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QDialog *UndoPreprocessing)
    {
        if (UndoPreprocessing->objectName().isEmpty())
            UndoPreprocessing->setObjectName(QStringLiteral("UndoPreprocessing"));
        UndoPreprocessing->resize(167, 80);
        pushButton = new QPushButton(UndoPreprocessing);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 40, 51, 21));
        pushButton_2 = new QPushButton(UndoPreprocessing);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(100, 40, 51, 21));
        label = new QLabel(UndoPreprocessing);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 131, 16));

        retranslateUi(UndoPreprocessing);

        QMetaObject::connectSlotsByName(UndoPreprocessing);
    } // setupUi

    void retranslateUi(QDialog *UndoPreprocessing)
    {
        UndoPreprocessing->setWindowTitle(QApplication::translate("UndoPreprocessing", "Dialog", 0));
        pushButton->setText(QApplication::translate("UndoPreprocessing", "Yes", 0));
        pushButton_2->setText(QApplication::translate("UndoPreprocessing", "NO", 0));
        label->setText(QApplication::translate("UndoPreprocessing", "Undo Preprocessing", 0));
    } // retranslateUi

};

namespace Ui {
    class UndoPreprocessing: public Ui_UndoPreprocessing {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNDOPREPROCESSING_H
