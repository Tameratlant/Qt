/********************************************************************************
** Form generated from reading UI file 'multimediawindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIMEDIAWINDOW_H
#define UI_MULTIMEDIAWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_multimediawindow
{
public:

    void setupUi(QWidget *multimediawindow)
    {
        if (multimediawindow->objectName().isEmpty())
            multimediawindow->setObjectName(QString::fromUtf8("multimediawindow"));
        multimediawindow->resize(400, 300);

        retranslateUi(multimediawindow);

        QMetaObject::connectSlotsByName(multimediawindow);
    } // setupUi

    void retranslateUi(QWidget *multimediawindow)
    {
        multimediawindow->setWindowTitle(QCoreApplication::translate("multimediawindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class multimediawindow: public Ui_multimediawindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIMEDIAWINDOW_H
