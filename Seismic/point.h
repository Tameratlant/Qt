#pragma once
#include <QPoint>

class Point : public QPoint {
public:
    Point() : QPoint() {} // Конструктор по умолчанию
    Point(int x, int y) : QPoint(x, y) {} // Конструктор с координатами
    Point(QPoint otherPoint) : Point(otherPoint.x (), otherPoint.y ()) {}
};
