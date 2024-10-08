/********************************************************************************
** Form generated from reading UI file 'secondwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDWINDOW_H
#define UI_SECONDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SecondWindow
{
public:
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;

    void setupUi(QWidget *SecondWindow)
    {
        if (SecondWindow->objectName().isEmpty())
            SecondWindow->setObjectName(QString::fromUtf8("SecondWindow"));
        SecondWindow->resize(596, 438);
        comboBox = new QComboBox(SecondWindow);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(490, 40, 86, 25));
        comboBox_2 = new QComboBox(SecondWindow);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(490, 100, 86, 25));
        comboBox_3 = new QComboBox(SecondWindow);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(490, 150, 86, 25));
        comboBox_4 = new QComboBox(SecondWindow);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setGeometry(QRect(490, 200, 86, 25));

        retranslateUi(SecondWindow);

        QMetaObject::connectSlotsByName(SecondWindow);
    } // setupUi

    void retranslateUi(QWidget *SecondWindow)
    {
        SecondWindow->setWindowTitle(QCoreApplication::translate("SecondWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecondWindow: public Ui_SecondWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDWINDOW_H
