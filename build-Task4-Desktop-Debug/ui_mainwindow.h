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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *toolBar;
    QComboBox *shapes;
    QPushButton *newPore;
    QComboBox *patterns;
    QPushButton *pushButton;
    QHBoxLayout *denInLayout;
    QLabel *label;
    QLineEdit *density_in;
    QHBoxLayout *denOutLayout;
    QLabel *label_2;
    QLineEdit *densit_out;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *collumns_num;
    QLabel *label_4;
    QLineEdit *rows_num;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *angle;
    QPushButton *OK;
    QPushButton *save;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(520, 100, 280, 421));
        toolBar = new QVBoxLayout(verticalLayoutWidget);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setContentsMargins(0, 0, 0, 0);
        shapes = new QComboBox(verticalLayoutWidget);
        shapes->setObjectName(QString::fromUtf8("shapes"));

        toolBar->addWidget(shapes);

        newPore = new QPushButton(verticalLayoutWidget);
        newPore->setObjectName(QString::fromUtf8("newPore"));

        toolBar->addWidget(newPore);

        patterns = new QComboBox(verticalLayoutWidget);
        patterns->setObjectName(QString::fromUtf8("patterns"));

        toolBar->addWidget(patterns);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        toolBar->addWidget(pushButton);

        denInLayout = new QHBoxLayout();
        denInLayout->setObjectName(QString::fromUtf8("denInLayout"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        denInLayout->addWidget(label);

        density_in = new QLineEdit(verticalLayoutWidget);
        density_in->setObjectName(QString::fromUtf8("density_in"));

        denInLayout->addWidget(density_in);


        toolBar->addLayout(denInLayout);

        denOutLayout = new QHBoxLayout();
        denOutLayout->setObjectName(QString::fromUtf8("denOutLayout"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        denOutLayout->addWidget(label_2);

        densit_out = new QLineEdit(verticalLayoutWidget);
        densit_out->setObjectName(QString::fromUtf8("densit_out"));

        denOutLayout->addWidget(densit_out);


        toolBar->addLayout(denOutLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        collumns_num = new QLineEdit(verticalLayoutWidget);
        collumns_num->setObjectName(QString::fromUtf8("collumns_num"));

        horizontalLayout_5->addWidget(collumns_num);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        rows_num = new QLineEdit(verticalLayoutWidget);
        rows_num->setObjectName(QString::fromUtf8("rows_num"));

        horizontalLayout_5->addWidget(rows_num);


        toolBar->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_6->addWidget(label_5);

        angle = new QLineEdit(verticalLayoutWidget);
        angle->setObjectName(QString::fromUtf8("angle"));

        horizontalLayout_6->addWidget(angle);


        toolBar->addLayout(horizontalLayout_6);

        OK = new QPushButton(verticalLayoutWidget);
        OK->setObjectName(QString::fromUtf8("OK"));

        toolBar->addWidget(OK);

        save = new QPushButton(verticalLayoutWidget);
        save->setObjectName(QString::fromUtf8("save"));

        toolBar->addWidget(save);

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
        newPore->setText(QCoreApplication::translate("MainWindow", "Custom Pore", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Cusom Pattern", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Density In:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Density Out:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Collumns", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Rows", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Angle", nullptr));
        OK->setText(QCoreApplication::translate("MainWindow", "Ok", nullptr));
        save->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
