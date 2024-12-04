#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "custom_pore_dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->toolBar->addWidget(ui->shapes);
    //ui->toolBar->addWidget(ui->newPore);
    //ui->toolBar->addWidget(ui->OK);
    //ui->toolBar->addWidget(ui->density_in);
    //ui->toolBar->addWidget(ui->save);
    // Настройка комбобокса
    ui->shapes->addItem("Simple Fissure");
    ui->shapes->addItem("Thin Fissure");
    ui->shapes->addItem("Eliptic pore");
    ui->patterns->addItem("Displaced Row");
    // ... добавить другие фигуры

    // Соединение сигналов и слотов
    //connect(ui->newPore, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
    //connect(ui->OK, SIGNAL(clicked()), this, SLOT(on_pushButton_2_clicked()));
    connect(ui->newPore, &QPushButton::clicked, this, &MainWindow::custom_pore_dialog_open);

}
/*
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    // Здесь будет реализована логика рисования фигур
    // В зависимости от выбранной формы и параметров
}

void MainWindow::on_pushButton_clicked()
{
    // Получение параметров из комбобокса и line edit
    QString selectedShape = ui->shapes->currentText();
    double density = ui->density->text().toDouble();

    // Вызов функции рисования фигуры
    drawShape(selectedShape, density);
}
*/
/*
void MainWindow::on_pushButton_2_clicked()
{
    // Создание и отображение диалога для добавления новой фигуры
    AddFigureDialog dialog;
    dialog.exec();
}
*/
void MainWindow::drawShape(QString shape, double density)
{
    QPainter painter(this);
    // ... логика рисования фигур
    if (shape == "Круг") {
        painter.drawEllipse(100, 100, 50, 50);
    } else if (shape == "Квадрат") {
        painter.drawRect(100, 100, 50, 50);
    }
    // ... другие фигуры
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::custom_pore_dialog_open ()
{

    if (!input_dialog) {
            input_dialog = new custom_pore_dialog;
            input_dialog->show();
        } else {
            input_dialog->show(); // Если окно уже создано, просто покажем его
        }

    // После закрытия диалогового окна, значение будет доступно в inputDialog->inputValue()
    // Здесь можно сохранить это значение в переменной или использовать его для дальнейших действий
}
