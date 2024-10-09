/*
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Устанавливаем фокус на главном окне, чтобы события мыши обрабатывались
    this->setFocusPolicy(Qt::StrongFocus);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QPoint pos = event->pos();
    QString coordinates = QString("Текущие координаты: (%1, %2)").arg(pos.x()).arg(pos.y());
    ui->label->setText(coordinates);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        QString clickCoordinates = QString("Координаты клика: (%1, %2)").arg(event->x()).arg(event->y());
        ui->label_2->setText(clickCoordinates);
    }
}
