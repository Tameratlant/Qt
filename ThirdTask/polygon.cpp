#include "polygon.h"
#include "reorder.cpp"

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
    void Polygon::reorderPoints() {
        QList<Point> tmp = grahamScan(points);
        points.clear();
        points = tmp;
    }

    void Polygon::fillEdges() {
        for (int i = 0; i < points.size(); ++i) {
            if (i == points.size() - 1)
            {
                auto start = std::make_shared<Point>(points[i]);
                auto end = std::make_shared<Point>(points[0]);

                Edge tmp(start, end);
                edges.append(tmp);
                //points[i].right = std::make_shared<Edge>(tmp);
                //points[0].left = std::make_shared<Edge>(tmp);
            }
            auto start = std::make_shared<Point>(points[i]);
            auto end = std::make_shared<Point>(points[i+1]);

            Edge tmp(start, end);
            edges.append(tmp);
            //points[i].right = std::make_shared<Edge>(tmp);
            //points[i+1].left = std::make_shared<Edge>(tmp);
        }
    }
