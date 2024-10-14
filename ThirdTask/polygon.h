#ifndef POLYGON_H
#define POLYGON_H

#include <QList>
#include <QPainter>
#include "point.h"

class Polygon {
public:
    QList<QPoint> points;

    void addPoint(const QPoint &point) { points.append(point); }
    void draw(QPainter& painter);
};

#endif // POLYGON_H
