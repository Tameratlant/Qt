#ifndef POLYGON_H
#define POLYGON_H

#include <QList>
#include <QPainter>
#include <QDebug>
#include "edge.h"
#include "point.h"

class Polygon {
public:
    QList<Point> points;
    QList<Edge> edges;
    void addPoint(const Point point) { points.append(point); }
    void draw(QPainter& painter);
    void reorderPoints();
    void fillEdges();
    void fillPoints();
    bool isPointInsidePolygon(const Point& point);
};

#endif // POLYGON_H
