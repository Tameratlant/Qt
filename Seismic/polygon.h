#ifndef POLYGON_H
#define POLYGON_H

#include <QList>
#include <QPainter>
#include <QDebug>
#include "edge.h"
#include "point.h"

class Polygon {
    QList<Point> points;

public:
    QList<Edge> edges;
    Polygon(QList<Point> &Qpoints);

    void addPoint(const Point point) { points.append(point); }
    void draw(QPainter& painter);
    void reorderPoints();
    void fillEdges();
    void fillPoints();
    bool isPointInsidePolygon(const Point& point);
};

#endif // POLYGON_H
