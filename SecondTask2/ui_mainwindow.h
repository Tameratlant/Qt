/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *controlLayout;
    QPushButton *go2MouseHandlerBtn;
    QPushButton *go2MultimediaBtn;
    QWidget *layoutWidget_2;
    QHBoxLayout *mainLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(290, 260, 206, 27));
        controlLayout = new QHBoxLayout(layoutWidget);
        controlLayout->setObjectName(QString::fromUtf8("controlLayout"));
        controlLayout->setContentsMargins(0, 0, 0, 0);
        go2MouseHandlerBtn = new QPushButton(layoutWidget);
        go2MouseHandlerBtn->setObjectName(QString::fromUtf8("go2MouseHandlerBtn"));

        controlLayout->addWidget(go2MouseHandlerBtn);

        go2MultimediaBtn = new QPushButton(layoutWidget);
        go2MultimediaBtn->setObjectName(QString::fromUtf8("go2MultimediaBtn"));

        controlLayout->addWidget(go2MultimediaBtn);

        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(290, 260, 2, 2));
        mainLayout = new QHBoxLayout(layoutWidget_2);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        mainLayout->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        go2MouseHandlerBtn->setText(QCoreApplication::translate("MainWindow", "Mouse Handler", nullptr));
        go2MultimediaBtn->setText(QCoreApplication::translate("MainWindow", "Multimedia", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
