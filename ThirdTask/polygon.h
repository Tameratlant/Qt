#ifndef POLYGON_H
#define POLYGON_H

#include <QList>
#include "point.h"

class Polygon {
public:
    QList<Point> points;

    void addPoint(const Point& point) { points.append(point); }
    void draw(QPainter& painter);
};

#endif // POLYGON_H
