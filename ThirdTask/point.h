#ifndef POINT_H
#define POINT_H
#include <QPoint>
#include <edge.h>

class Point : public QPoint {

public:

    //std::shared_ptr<Edge> left;
    //std::shared_ptr<Edge> right;

    Point() : QPoint() {} // Конструктор по умолчанию
    Point(int x, int y) : QPoint(x, y) {} // Конструктор с координатами

    };

#endif // POINT_H
