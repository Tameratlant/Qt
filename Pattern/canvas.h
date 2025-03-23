#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QList>
#include "shape_types.h" // Подключаем наш enum

struct Shape {
    ShapeType type; // Тип фигуры (используем enum)
    QPointF position; // Позиция фигуры
    QSizeF size; // Размер фигуры
    int rotation; // Угол поворота
};

class Canvas : public QWidget
{
    Q_OBJECT

public:
    explicit Canvas(QWidget *parent = nullptr);
    void setShapeType(ShapeType type); // Используем enum
    void setShapeSize(int width, int height);
    void setShapeRotation(int angle);
    void setActiveShape(int index); // Установить активную фигуру


protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    ShapeType currentShapeType; // Текущий тип фигуры (используем enum)
    QList<Shape> shapes; // Список всех фигур
    int activeShapeIndex; // Индекс активной фигуры

    QSizeF getDefaultSize(ShapeType type);
    void drawShape(QPainter &painter, const Shape &shape);
};

#endif // CANVAS_H
