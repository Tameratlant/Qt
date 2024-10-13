#include "polygon.h"


void Polygon::draw(QPainter& painter) {
    QPolygonF polygon;
    for (const Point& point : points) {
        polygon << QPointF(point.x, point.y);
    }
    painter.drawPolygon(polygon);
}
