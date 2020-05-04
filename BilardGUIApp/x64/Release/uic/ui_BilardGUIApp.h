/********************************************************************************
** Form generated from reading UI file 'BilardGUIApp.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BILARDGUIAPP_H
#define UI_BILARDGUIAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BilardGUIAppClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BilardGUIAppClass)
    {
        if (BilardGUIAppClass->objectName().isEmpty())
            BilardGUIAppClass->setObjectName(QString::fromUtf8("BilardGUIAppClass"));
        BilardGUIAppClass->resize(600, 400);
        menuBar = new QMenuBar(BilardGUIAppClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        BilardGUIAppClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(BilardGUIAppClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        BilardGUIAppClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(BilardGUIAppClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        BilardGUIAppClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(BilardGUIAppClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        BilardGUIAppClass->setStatusBar(statusBar);

        retranslateUi(BilardGUIAppClass);

        QMetaObject::connectSlotsByName(BilardGUIAppClass);
    } // setupUi

    void retranslateUi(QMainWindow *BilardGUIAppClass)
    {
        BilardGUIAppClass->setWindowTitle(QCoreApplication::translate("BilardGUIAppClass", "BilardGUIApp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BilardGUIAppClass: public Ui_BilardGUIAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BILARDGUIAPP_H
