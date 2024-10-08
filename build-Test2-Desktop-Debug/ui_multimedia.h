/********************************************************************************
** Form generated from reading UI file 'Multimedia.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_Multimedia_H
#define UI_Multimedia_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Multimedia
{
public:
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;

    void setupUi(QWidget *Multimedia)
    {
        if (Multimedia->objectName().isEmpty())
            Multimedia->setObjectName(QString::fromUtf8("Multimedia"));
        Multimedia->resize(590, 465);
        comboBox = new QComboBox(Multimedia);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(470, 60, 86, 25));
        comboBox_2 = new QComboBox(Multimedia);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(470, 130, 86, 25));
        comboBox_3 = new QComboBox(Multimedia);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(470, 200, 86, 25));
        comboBox_4 = new QComboBox(Multimedia);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setGeometry(QRect(470, 260, 86, 25));

        retranslateUi(Multimedia);

        QMetaObject::connectSlotsByName(Multimedia);
    } // setupUi

    void retranslateUi(QWidget *Multimedia)
    {
        Multimedia->setWindowTitle(QCoreApplication::translate("Multimedia", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Multimedia: public Ui_Multimedia {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_Multimedia_H
