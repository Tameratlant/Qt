/********************************************************************************
** Form generated from reading UI file 'custom_pore_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOM_PORE_DIALOG_H
#define UI_CUSTOM_PORE_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_custom_pore_dialog
{
public:
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QWidget *custom_pore_dialog)
    {
        if (custom_pore_dialog->objectName().isEmpty())
            custom_pore_dialog->setObjectName(QString::fromUtf8("custom_pore_dialog"));
        custom_pore_dialog->resize(484, 354);
        lineEdit = new QLineEdit(custom_pore_dialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(150, 120, 113, 25));
        label = new QLabel(custom_pore_dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 60, 431, 17));

        retranslateUi(custom_pore_dialog);

        QMetaObject::connectSlotsByName(custom_pore_dialog);
    } // setupUi

    void retranslateUi(QWidget *custom_pore_dialog)
    {
        custom_pore_dialog->setWindowTitle(QCoreApplication::translate("custom_pore_dialog", "Form", nullptr));
        label->setText(QCoreApplication::translate("custom_pore_dialog", "\320\227\320\264\320\265\321\201\321\214 \320\261\321\203\320\264\320\265\321\202 \320\264\320\270\320\260\320\273\320\276\320\263 \321\201 \320\264\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265\320\274 \321\201\320\262\320\276\320\265\320\271 \320\277\320\276\321\200\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class custom_pore_dialog: public Ui_custom_pore_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOM_PORE_DIALOG_H
