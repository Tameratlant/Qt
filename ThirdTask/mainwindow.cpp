#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPainter>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // Создаем главный вертикальный layout
    //QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget());
    QVBoxLayout* mainLayout = ui->verticalLayout;
    // Создаем layout для полей ввода и кнопки
    inputLayout = new QVBoxLayout;

    // Создаем 5 пар полей для ввода координат
    for (int i = 0; i < 3; ++i) {
        QLabel* labelX = new QLabel("X:");
        QLineEdit* editX = new QLineEdit;
        QLabel* labelY = new QLabel("Y:");
        QLineEdit* editY = new QLineEdit;
        inputLayout->addWidget(labelX);
        inputLayout->addWidget(editX);
        inputLayout->addWidget(labelY);
        inputLayout->addWidget(editY);
        inputFields.append(editX);
        inputFields.append(editY);
    }

    // Кнопка ОК
    QPushButton* okButton = new QPushButton("ОК");
    inputLayout->addWidget(okButton);

    // Добавляем layout с полями ввода в главный layout
    mainLayout->addLayout(inputLayout);

    // Подключаем сигнал к слоту
    connect(okButton, &QPushButton::clicked, this, &MainWindow::on_okButton_clicked);
}

void MainWindow::on_okButton_clicked() {
    // Считываем данные из полей ввода и добавляем точки в полигон
    for (int i = 0; i < inputFields.size(); i += 2) {
        bool ok;
        double x = inputFields.at(i)->text().toDouble(&ok);
        double y = inputFields.at(i + 1)->text().toDouble(&ok);
        if (ok) {
            polygon.addPoint({x, y});
        } else {
            QMessageBox::warning(this, "Ошибка", "Некорректный ввод координат");
            return;
        }
    }

    // Скрываем layout с полями ввода
    //inputLayout->setVisible(false);
    for (int i = 0; i < inputLayout->count(); ++i) {
           QWidget *widget = inputLayout->itemAt(i)->widget();
           if (widget) {
               widget->hide();
           }
       }
    // Перерисовываем окно
    drawPolygon();
    update();
}

void MainWindow::drawPolygon() {
    qDebug() << "!!!";
    QPainter painter(this);
    polygon.draw(painter);
}

MainWindow::~MainWindow()
{
    delete ui;
}
