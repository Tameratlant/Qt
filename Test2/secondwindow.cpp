#include "secondwindow.h"

#include <QPainter>
#include <QColor>
#include <QPen>
#include <QBrush>

SecondWindow::SecondWindow(QWidget *parent) : QWidget(parent)
{
    figureComboBox = new QComboBox(this);
    figureComboBox->addItem("Треугольник");
    figureComboBox->addItem("Круг");
    // ... другие фигуры

    colorComboBox = new QComboBox(this);
    colorComboBox->addItem("Зеленый");
    colorComboBox->addItem("Красный");
    // ... другие цвета

    borderComboBox = new QComboBox(this);
    borderComboBox->addItem("Сплошная");
    borderComboBox->addItem("Пунктирная");
    // ... другие типы границ

    fillComboBox = new QComboBox(this);
    fillComboBox->addItem("Сплошная");
    fillComboBox->addItem("Диагональная штриховка");
    // ... другие типы заливки

    figureLabel = new QLabel(this);

    // Расположение элементов на форме (можно использовать layout)
    // ...

    connect(figureComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &SecondWindow::updateFigure);
    connect(colorComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &SecondWindow::updateFigure);
    connect(borderComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &SecondWindow::updateFigure);
    connect(fillComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &SecondWindow::updateFigure);

    updateFigure();
}

void SecondWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    // Определяем параметры фигуры на основе выбранных значений
    QColor color;
    Qt::PenStyle penStyle;
    Qt::BrushStyle brushStyle;

    switch (colorComboBox->currentIndex()) {
        case 0:
            color = Qt::green;
            break;
        // ... другие цвета
    }

    switch (borderComboBox->currentIndex()) {
        case 0:
            penStyle = Qt::SolidLine;
            break;
        case 1:
            penStyle = Qt::DashLine;
            break;
        // ... другие стили линий
    }

    switch (fillComboBox->currentIndex()) {
        case 0:
            brushStyle = Qt::SolidPattern;
            break;
        case 1:
            brushStyle = Qt::DiagCrossPattern;
            break;
        // ... другие стили заливки
    }

    QPen pen(color, 2, penStyle);
    QBrush brush(color, brushStyle);
    painter.setPen(pen);
    painter.setBrush(brush);

    // Рисуем фигуру в зависимости от выбранного типа
    switch (figureComboBox->currentIndex()) {
        case 0: // Треугольник
    {
            QPolygon triangle;
            triangle << QPoint(50, 10) << QPoint(100, 100) << QPoint(10, 100);
            painter.drawPolygon(triangle);
            break;
    }
        case 1: // Круг
    {
            painter.drawEllipse(50, 50, 50, 50);
            break;
        // ... другие фигуры
    }
    }
}

void SecondWindow::updateFigure()
{
    // Обновление параметров фигуры на основе выбранных значений
    // ...

    update();
}
