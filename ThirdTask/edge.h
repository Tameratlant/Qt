#ifndef EDGE_H
#define EDGE_H
#include "point.h"
#include <QColor>
#include <memory>
class Edge {
public:
    std::shared_ptr<Point> A;
    std::shared_ptr<Point> B;
    QColor color = Qt::black;
    Edge(std::shared_ptr<Point> A_, std::shared_ptr<Point> B_) : A(A_), B(B_) {}
};

#endif // EDGE_H
