#include "canvas.h"
#include <QPainter>
#include "polygon.h"
#include <QtMath>

Canvas::Canvas(QWidget *parent) : QWidget(parent), currentShapeType(ShapeType::unknown), activeShapeIndex(-1)
{
    setFixedSize(800, 600);
}

void Canvas::setShapeType(ShapeType type)
{
    currentShapeType = type;
}

QList<Point> shapeUpdate(Shape shape)
{
    QList<Point> points;
    int pointCount;
    const qreal centerX = shape.position.x();
    const qreal centerY = shape.position.y();
    const qreal halfWidth = shape.size.width() / 2.0;
    const qreal halfHeight = shape.size.height() / 2.0;
    const qreal angleRad = qDegreesToRadians(static_cast<qreal>(shape.rotation));

    auto rotatePoint = [&](qreal x, qreal y) -> QPoint {
        // Перенос в начало координат, поворот и обратный перенос
        qreal rotatedX = centerX + (x * qCos(angleRad) - y * qSin(angleRad));
        qreal rotatedY = centerY + (x * qSin(angleRad) + y * qCos(angleRad));
        return QPoint(rotatedX, rotatedY);
    };

    switch (shape.type) {
    case ShapeType::eleptic_pore: {
        pointCount = get_num_of_point_to_approx(shape.type);
        for (int i = 0; i < pointCount; ++i) {
            qreal angle = 2 * M_PI * i / pointCount;
            qreal x = halfWidth * qCos(angle);
            qreal y = halfHeight * qSin(angle);
            points.append(rotatePoint(x, y));
        }
        break;
    }
    case ShapeType::simple_fissure: {
        pointCount = get_num_of_point_to_approx(shape.type);
        int pointsPerSide = pointCount / 4;
        if (pointsPerSide < 1) pointsPerSide = 1;

        for (int i = 0; i < pointsPerSide; ++i) {
            qreal x = -halfWidth + (2 * halfWidth * i) / (pointsPerSide - 1);
            qreal y = -halfHeight;
            points.append(rotatePoint(x, y));
        }

        for (int i = 1; i < pointsPerSide; ++i) {
            qreal x = halfWidth;
            qreal y = -halfHeight + (2 * halfHeight * i) / (pointsPerSide - 1);
            points.append(rotatePoint(x, y));
        }

        for (int i = 1; i < pointsPerSide; ++i) {
            qreal x = halfWidth - (2 * halfWidth * i) / (pointsPerSide - 1);
            qreal y = halfHeight;
            points.append(rotatePoint(x, y));
        }

        for (int i = 1; i < pointsPerSide - 1; ++i) {
            qreal x = -halfWidth;
            qreal y = halfHeight - (2 * halfHeight * i) / (pointsPerSide - 1);
            points.append(rotatePoint(x, y));
        }
        return points;
    }
    case ShapeType::thin_fissure: {
        qreal x1 = -halfWidth;
        qreal y1 = 0;
        qreal x2 = halfWidth;
        qreal y2 = 0;
        points.append(rotatePoint(x1, y1));
        points.append(rotatePoint(x2, y2));
        return points;
        break;
    }
    default:
        break;
    }
    return points;
}

void Canvas::convertQShapeToPolygon()
{
    if (!Pshapes.empty ())
        Pshapes.clear ();
    for (auto &shape : shapes)
      Pshapes.push_back(shapeUpdate(shape));
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

void Canvas::setPos(QPoint pos)
{
    if (activeShapeIndex != -1 && activeShapeIndex < shapes.size()) {
        shapes[activeShapeIndex].position = pos;
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

    for (int i = 0; i < shapes.size(); ++i) {
        if (i == activeShapeIndex) {
            painter.setPen(Qt::red);
        } else {
            painter.setPen(Qt::black);
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
    /*
    if (currentShapeType == ShapeType::unknown)
    {
        for (auto &shape : shapes) {
            if (shape->contains(event->pos())) {
                selectedShape = shape;
                emit shapeSelected(true);
                update();
                break;
            }
        }
    }*/

    Shape newShape;
    newShape.type = currentShapeType;
    newShape.position = event->pos();
    newShape.size = getDefaultSize(newShape.type);
    newShape.rotation = 0;

    shapes.append(newShape);
    activeShapeIndex = shapes.size() - 1;
    update();
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

    painter.restore();
}
