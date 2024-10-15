#include "polygon.h"
#include "reorder.cpp"
/*
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
*/

void Polygon::draw(QPainter &painter) {
    // Проходим по всем ребрам
    for (const auto &edge : this->edges) {
        // Устанавливаем цвет пера
        painter.setPen(QPen(edge.color));

        // Рисуем линию между точками
        painter.drawLine(QPoint(edge.A.x(), edge.A.y()), QPoint(edge.B.x(), edge.B.y()));
    }
}
void Polygon::reorderPoints() {
    QList<Point> tmp = grahamScan(points);
    points.clear();
    points = tmp;
}

void Polygon::fillEdges() {
    qDebug() << "size" << points.size();
    for (int i = 0; i < points.size(); ++i) {
        if (i == points.size() - 1)
        {
            //auto start = std::make_shared<Point>(points[points.size() - 1]);
            //auto end = std::make_shared<Point>(points[0]);
            //Edge tmp(start, end);
            Edge tmp(points[points.size() - 1], points[0]);
            edges.append(tmp);
            //points[i].right = std::make_shared<Edge>(tmp);
            //points[0].left = std::make_shared<Edge>(tmp);
            break;
        }
        //auto start = std::make_shared<Point>(points[i]);
        //auto end = std::make_shared<Point>(points[i+1]);
        //Edge tmp(start, end);
        Edge tmp(points[i], points[i+1]);
        edges.append(tmp);
        //points[i].right = std::make_shared<Edge>(tmp);
        //points[i+1].left = std::make_shared<Edge>(tmp);
    }
}
bool Polygon::isPointInsidePolygon(const Point& point) {
    int n = points.size();

    // Если многоугольник пустой или содержит меньше 3 точек, точка не может находиться внутри
    if (n < 3) {
        return false;
    }

    // Используем алгоритм "ray casting" (проецирование луча)
    // Проверяем пересечение луча, идущего от точки вправо, со сторонами многоугольника
    int intersections = 0;
    for (int i = 0; i < n; i++) {
        // Текущая и следующая точки многоугольника
        const Point& p1 = points[i];
        const Point& p2 = points[(i + 1) % n];

        // Проверяем, пересекает ли луч горизонтальную линию, проходящую через точку
        if (((p1.y() <= point.y() && p2.y() > point.y()) ||
             (p2.y() <= point.y() && p1.y() > point.y())) &&
                (point.x() < (p2.x() - p1.x()) * (point.y() - p1.y()) / (p2.y() - p1.y()) + p1.x())) {
            intersections++;
        }
    }

    // Если количество пересечений нечетное, точка находится внутри многоугольника
    return intersections % 2 == 1;
}

