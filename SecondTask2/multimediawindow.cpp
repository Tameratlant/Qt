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
    connect(fillComboBox, QOverload<int>::of(&QQComboBox::currentIndexChanged), this, &SecondWindow::updateFigure);

    updateFigure();
}

void SecondWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    // Определение параметров фигуры на основе выбранных значений
    // ...

    // Рисование фигуры
    painter.drawPath(path);
}

void SecondWindow::updateFigure()
{
    // Обновление параметров фигуры на основе выбранных значений
    // ...

    update();
}
