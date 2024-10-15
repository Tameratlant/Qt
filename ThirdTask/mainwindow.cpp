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
#include <QtWidgets>
#include <QColor>
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
    /*
    for (int i = 0; i < edgesLayout->count(); ++i) {
        QWidget *widget = edgesLayout->itemAt(i)->widget();
        if (widget) {
            widget->hide();
        }
    }
    */
}

void MainWindow::showInputFields() {
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
    //drawPolygon();
    //update();
    setMouseTracking(true);
    showInputFields();
}

void MainWindow::showEdgesSettings() {
    QVBoxLayout* edgesLayout = ui->edgesLayout;
    // Создаем layout для полей ввода и кнопки
    auto title = new QLabel("Ребра:(введите цвета)");
    edgesInputLayout = new QVBoxLayout;
    for (int i = 0; i < n-1; ++i) {
        std::string title = std::to_string(i+1)+"=====>" + std::to_string(i+2);
        QLabel* title_i = new QLabel(QString::fromStdString(title));
        QLineEdit* edge_i = new QLineEdit;
        edgesInputLayout->addWidget(title_i);
        edgesInputLayout->addWidget(edge_i);
        colorInputFields.append(edge_i);
    }
    std::string title_0 = std::to_string(n)+"=====>" + std::to_string(1);
    QLabel* title_i = new QLabel(QString::fromStdString(title_0));
    QLineEdit* edge_i = new QLineEdit;
    edgesInputLayout->addWidget(title_i);
    edgesInputLayout->addWidget(edge_i);
    colorInputFields.append(edge_i);
    edgesLayout->addWidget(title);
    // Добавляем layout с полями ввода в главный layout
    edgesLayout->addLayout(edgesInputLayout);
}

void MainWindow::on_okButton_clicked() {
    polygon.points.clear();
    polygon.edges.clear();

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
    for (int i = 0; i < inputLayout->count(); ++i) {
        QWidget *widget = inputLayout->itemAt(i)->widget();
        if (widget) {
            widget->hide();
        }
    }
    for (int i = 0; i < points_num_layout->count(); ++i) {
        QWidget *widget = points_num_layout->itemAt(i)->widget();
        if (widget) {
            widget->hide();
        }
    }
    QHBoxLayout *innerLayout = points_num_layout->findChild<QHBoxLayout*>("n_ok_laytout");
    for (int i = 0; i < innerLayout->count(); ++i) {
        QWidget *widget = innerLayout->itemAt(i)->widget();
        if (widget) {
            widget->hide();
        }
    }
    /*
    for (int i = 0; i < colorInputFields.size(); i++) {
        QString colorText = colorInputFields.at(i)->text();
        QColor color;
        color.setNamedColor(colorText);
        if (color.isValid()) {
            // Цвет успешно преобразован
            polygon.edges[i].color = color;
        } else {
            // Некорректный ввод цвета
            qDebug() << "Неверный формат цвета в поле №" << i+1;
            // Можно добавить сообщение об ошибке для пользователя
        }
    }
    for (int i = 0; i < edgesLayout->count(); ++i) {
        QWidget *widget = edgesLayout->itemAt(i)->widget();
        if (widget) {
            widget->hide();
        }
    }
    QHBoxLayout *inner2Layout = points_num_layout->findChild<QHBoxLayout*>("edgesInputLayout");
    for (int i = 0; i < inner2Layout->count(); ++i) {
        QWidget *widget = innerLayout->itemAt(i)->widget();
        if (widget) {
            widget->hide();
        }
    }
    */
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

    if (event->button() == Qt::LeftButton) {
        int x = event->pos().x();
        int y = height() - event->pos().y();
        Point point(x,y);
        for (int i = 0; i < points_num_layout->count(); ++i) {
            QWidget *widget = points_num_layout->itemAt(i)->widget();
            if (widget) {
                widget->show();
            }
        }
        QHBoxLayout *innerLayout = points_num_layout->findChild<QHBoxLayout*>("n_ok_laytout");
        for (int i = 0; i < innerLayout->count(); ++i) {
            QWidget *widget = innerLayout->itemAt(i)->widget();
            if (widget) {
                widget->show();
            }
        }
        polygon.points.clear();
        //showEdgesSettings();
        //inputFields.clear();
        // Перерисовываем окно
        //drawPolygon();
        //update();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
