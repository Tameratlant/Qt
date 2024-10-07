#include "secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent) : QWidget(parent)
{
    QLabel *label = new QLabel("Опездол2", this);
    label->setAlignment(Qt::AlignCenter);
}
