/********************************************************************************
** Form generated from reading UI file 'groundtruth.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUNDTRUTH_H
#define UI_GROUNDTRUTH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GroundTruth
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GroundTruth)
    {
        if (GroundTruth->objectName().isEmpty())
            GroundTruth->setObjectName(QStringLiteral("GroundTruth"));
        GroundTruth->resize(458, 123);
        centralWidget = new QWidget(GroundTruth);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(170, 20, 81, 22));
        GroundTruth->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GroundTruth);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 458, 19));
        GroundTruth->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GroundTruth);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GroundTruth->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GroundTruth);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GroundTruth->setStatusBar(statusBar);

        retranslateUi(GroundTruth);

        QMetaObject::connectSlotsByName(GroundTruth);
    } // setupUi

    void retranslateUi(QMainWindow *GroundTruth)
    {
        GroundTruth->setWindowTitle(QApplication::translate("GroundTruth", "GroundTruth", 0));
        pushButton->setText(QApplication::translate("GroundTruth", "Load Image", 0));
    } // retranslateUi

};

namespace Ui {
    class GroundTruth: public Ui_GroundTruth {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUNDTRUTH_H
