/********************************************************************************
** Form generated from reading UI file 'firstwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIRSTWINDOW_H
#define UI_FIRSTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_firstwindow
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *realtime_lineEdit;
    QLabel *static_lineEdit;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;

    void setupUi(QWidget *firstwindow)
    {
        if (firstwindow->objectName().isEmpty())
            firstwindow->setObjectName(QString::fromUtf8("firstwindow"));
        firstwindow->resize(400, 300);
        layoutWidget = new QWidget(firstwindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 36, 42));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        realtime_lineEdit = new QLabel(layoutWidget);
        realtime_lineEdit->setObjectName(QString::fromUtf8("realtime_lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(realtime_lineEdit->sizePolicy().hasHeightForWidth());
        realtime_lineEdit->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(realtime_lineEdit, 1, 1, 1, 1);

        static_lineEdit = new QLabel(layoutWidget);
        static_lineEdit->setObjectName(QString::fromUtf8("static_lineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(static_lineEdit->sizePolicy().hasHeightForWidth());
        static_lineEdit->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(static_lineEdit, 2, 1, 1, 1);

        layoutWidget_2 = new QWidget(firstwindow);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(0, 0, 407, 19));
        horizontalLayout = new QHBoxLayout(layoutWidget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);


        retranslateUi(firstwindow);

        QMetaObject::connectSlotsByName(firstwindow);
    } // setupUi

    void retranslateUi(QWidget *firstwindow)
    {
        firstwindow->setWindowTitle(QCoreApplication::translate("firstwindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("firstwindow", "#1", nullptr));
        label_2->setText(QCoreApplication::translate("firstwindow", "#2", nullptr));
        realtime_lineEdit->setText(QString());
        static_lineEdit->setText(QString());
        label_3->setText(QCoreApplication::translate("firstwindow", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \321\203\320\272\320\260\320\267\320\260\320\275\321\213 \320\276\321\202\320\275\320\276\321\201\320\270\321\202\320\265\320\273\321\214\320\275\320\276 \320\273\320\265\320\262\320\276\320\263\320\276 \320\275\320\270\320\266\320\275\320\265\320\263\320\276 \321\203\320\263\320\273\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class firstwindow: public Ui_firstwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRSTWINDOW_H
