#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    // Создаем второе окно и скрываем его

    mouse = new Mouse(this);
    mouse->hide();
    secondWindow = new SecondWindow(this);
    secondWindow->hide();
    QSize size = this->size();
    // Центрируем кнопку на главном окне
    ui->pushButton1->setGeometry(size.width()/3, size.height()/2, size.width()/6, 30);
    ui->pushButton1->setText("Кнопк1");
    ui->pushButton2->setGeometry(size.width()/3*2, size.height()/2, size.width()/6, 30);
    ui->pushButton2->setText("Кнопк2");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete secondWindow;
}

void MainWindow::on_pushButton1_clicked()
{
    // Скрываем главное меню
    //menuBar()->setVisible(false);
    QSize size = this->size();
    ui->pushButton1->setGeometry(size.width()/3, 10, size.width()/6, 30);
    // Показываем второе окно
    mouse->show();
    secondWindow->hide();
}

void MainWindow::on_pushButton2_clicked()
{
    // Скрываем главное меню
    //menuBar()->setVisible(false);
    QSize size = this->size();
    ui->pushButton2->setGeometry(size.width()/3*2, 10, size.width()/6, 30);
    // Показываем второе окно
    secondWindow->show();
    mouse->hide();
}
