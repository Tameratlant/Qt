#include "canvas.h"
#include <QPainter>

Canvas::Canvas(QWidget *parent) : QWidget(parent), currentShapeType(ShapeType::unknown), activeShapeIndex(-1)
{
    setFixedSize(800, 600);
}

void Canvas::setShapeType(ShapeType type)
{
    currentShapeType = type;
}

void Canvas::setShapeSize(int width, int height)
{
    if (activeShapeIndex != -1 && activeShapeIndex < shapes.size()) {
        shapes[activeShapeIndex].size = QSizeF(width, height);
        update();
    }
}

void Canvas::setShapeRotation(int angle)
{
    if (activeShapeIndex != -1 && activeShapeIndex < shapes.size()) {
        shapes[activeShapeIndex].rotation = angle;
        update();
    }
}

void Canvas::setActiveShape(int index)
{
    if (index >= 0 && index < shapes.size()) {
        activeShapeIndex = index;
        update();
    }
}

void Canvas::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    // Рисуем все фигуры из списка
    for (int i = 0; i < shapes.size(); ++i) {
        if (i == activeShapeIndex) {
            painter.setPen(Qt::red); // Активная фигура выделяется красным цветом
        } else {
            painter.setPen(Qt::black); // Остальные фигуры черным
        }
        drawShape(painter, shapes[i]);
    }
}

QSizeF Canvas::getDefaultSize(ShapeType type)
{
    switch (type) {
    case ShapeType::eleptic_pore:
        return QSizeF(30, 10);
    case ShapeType::simple_fissure:
        return QSizeF(2, 200);
    case ShapeType::thin_fissure:
        return QSizeF(0, 200);
    default:
        return QSizeF(100, 100);
    }
}

void Canvas::mousePressEvent(QMouseEvent *event)
{
    if (currentShapeType == ShapeType::unknown) return; // Если фигура не выбрана, ничего не делаем

    // Создаем новую фигуру и добавляем ее в список
    Shape newShape;
    newShape.type = currentShapeType;
    newShape.position = event->pos();
    //newShape.size = QSizeF(100, 100);
    newShape.size = getDefaultSize(newShape.type);
    newShape.rotation = 0;

    shapes.append(newShape);
    activeShapeIndex = shapes.size() - 1; // Делаем новую фигуру активной
    update(); // Перерисовываем холст
}

void Canvas::drawShape(QPainter &painter, const Shape &shape)
{
    painter.save();
    painter.translate(shape.position);
    painter.rotate(shape.rotation);

    switch (shape.type) {
    case ShapeType::eleptic_pore:
        painter.drawEllipse(QPointF(0, 0), shape.size.width() / 2, shape.size.height() / 2);
        break;
    case ShapeType::simple_fissure:
        painter.drawRect(-shape.size.width() / 2, -shape.size.height() / 2, shape.size.width(), shape.size.height());
        break;
    case ShapeType::thin_fissure:
        painter.drawRect(-shape.size.width() / 2, -shape.size.height() / 2, shape.size.width(), shape.size.height());
        break;
    default:
        break;
    }

    painter.restore(); // Восстанавливаем состояние painter
}
