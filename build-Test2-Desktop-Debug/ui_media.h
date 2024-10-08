/********************************************************************************
** Form generated from reading UI file 'media.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIA_H
#define UI_MEDIA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Media
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;

    void setupUi(QWidget *Media)
    {
        if (Media->objectName().isEmpty())
            Media->setObjectName(QString::fromUtf8("Media"));
        Media->resize(601, 466);
        verticalLayoutWidget = new QWidget(Media);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(430, 60, 161, 341));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout->addWidget(comboBox);

        comboBox_2 = new QComboBox(verticalLayoutWidget);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        verticalLayout->addWidget(comboBox_2);

        comboBox_3 = new QComboBox(verticalLayoutWidget);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));

        verticalLayout->addWidget(comboBox_3);

        comboBox_4 = new QComboBox(verticalLayoutWidget);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));

        verticalLayout->addWidget(comboBox_4);


        retranslateUi(Media);

        QMetaObject::connectSlotsByName(Media);
    } // setupUi

    void retranslateUi(QWidget *Media)
    {
        Media->setWindowTitle(QCoreApplication::translate("Media", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Media: public Ui_Media {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIA_H
