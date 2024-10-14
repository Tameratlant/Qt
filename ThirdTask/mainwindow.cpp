#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPainter>
#include <QMessageBox>
#include <QDebug>
#include <QList>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    points_num_layout = ui->points_num_layout;

    editN = new QLineEdit;
    QPushButton* nOkButton = new QPushButton("ОК");
    QHBoxLayout* n_ok = ui->n_ok_laytout;
    n_ok->addWidget(editN);
    n_ok->addWidget(nOkButton);
    connect(nOkButton, &QPushButton::clicked, this, &MainWindow::n_okButton_clicked);
    points_num_layout->addLayout(n_ok);





    QVBoxLayout* mainLayout = ui->verticalLayout;
    // Создаем layout для полей ввода и кнопки
    inputLayout = new QVBoxLayout;
    for (int i = 0; i < n; ++i) {
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

void MainWindow::n_okButton_clicked() {
    // Считываем данные из полей ввода и добавляем точки в полигон
    bool ok;
    int tmp = editN->text().toInt(&ok);
        if (ok) {
            n = tmp;
        } else {
            QMessageBox::warning(this, "Ошибка", "Некорректный ввод числа координат");
            return;
        }

    // Скрываем layout с полями ввода
    //inputLayout->setVisible(false);
    for (int i = 0; i < points_num_layout->count(); ++i) {
        QWidget *widget = points_num_layout->itemAt(i)->widget();
        if (widget) {
            widget->hide();
        }
    }

    // Перерисовываем окно
    drawPolygon();
    update();
    setMouseTracking(true);
}

void MainWindow::on_okButton_clicked() {
    // Считываем данные из полей ввода и добавляем точки в полигон
    for (int i = 0; i < inputFields.size(); i += 2) {
        bool ok;
        int x = inputFields.at(i)->text().toInt(&ok);
        int y = inputFields.at(i + 1)->text().toInt(&ok);
        if (ok) {
            qDebug() << x;
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
    setMouseTracking(true);
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    drawPolygon();
    QWidget::paintEvent(event);
}
void MainWindow::drawPolygon() {
    QPainter painter(this);
    polygon.draw(painter);
    painter.setPen(Qt::black);
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    qDebug() << "mousePressEvent";
    if (event->button() == Qt::LeftButton) {
        int x = event->pos().x();
        int y = height() - event->pos().y();
        Point point(x,y);
        qDebug() << "mousePressEvent";
        for (int i = 0; i < inputLayout->count(); ++i) {
            QWidget *widget = inputLayout->itemAt(i)->widget();
            if (widget) {
                widget->show();
            }
        }
        for (int i = 0; i < inputLayout->count(); ++i) {
            QWidget *widget = inputLayout->itemAt(i)->widget();
            if (widget) {
                widget->hide();
            }
        }
        polygon.points.clear();
        // Перерисовываем окно
        //drawPolygon();
        //update();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
