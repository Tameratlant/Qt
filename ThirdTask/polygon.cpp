#include "polygon.h"


void Polygon::draw(QPainter &painter) {
    if (points.size() < 2) {
        return; // Нужно минимум 2 точки для рисования
    }
    painter.setPen(Qt::black);

    // Рисуем линии между точками
    for (int i = 1; i < points.size(); ++i) {
        painter.drawLine(points[i - 1], points[i]);
    }

    // Дополнительная линия, чтобы замкнуть полигон
    if (points.size() > 2) {
        painter.drawLine(points.last(), points.first());
    }
}
