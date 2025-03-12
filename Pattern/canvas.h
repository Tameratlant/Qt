#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QList>

struct Shape {
    int type; // Тип фигуры (1 - треугольник, 2 - квадрат, 3 - круг)
    QPointF position; // Позиция фигуры
    QSizeF size; // Размер фигуры
    int rotation; // Угол поворота
};

class Canvas : public QWidget
{
    Q_OBJECT

public:
    explicit Canvas(QWidget *parent = nullptr);
    void setShapeType(int type);
    void setShapeSize(int width, int height);
    void setShapeRotation(int angle);
    void setActiveShape(int index); // Установить активную фигуру

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    int currentShapeType; // Текущий тип фигуры
    QList<Shape> shapes; // Список всех фигур
    int activeShapeIndex; // Индекс активной фигуры

    void drawShape(QPainter &painter, const Shape &shape);
};

#endif // CANVAS_H
