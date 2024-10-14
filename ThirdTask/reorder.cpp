#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <QPoint>
#include <QList>
#include <functional>
#include "point.h"

// Функция для сравнения точек по углу относительно заданной точки (pivot)
bool comparePoints(const Point& p1, const Point& p2, const Point& pivot) {
    double angle1 = atan2(p1.y() - pivot.y(), p1.x() - pivot.x());
    double angle2 = atan2(p2.y() - pivot.y(), p2.x() - pivot.x());

    // Если углы одинаковые, сортируем по расстоянию
    if (angle1 == angle2) {
        double dist1 = sqrt(pow(p1.x() - pivot.x(), 2) + pow(p1.y() - pivot.y(), 2));
        double dist2 = sqrt(pow(p2.x() - pivot.x(), 2) + pow(p2.y() - pivot.y(), 2));
        return dist1 < dist2;
    }

    return angle1 < angle2;
}

// Функция для проверки типа поворота трех точек
int ccw(const Point& a, const Point& b, const Point& c) {
    int area = (b.x() - a.x()) * (c.y() - a.y()) - (b.y() - a.y()) * (c.x() - a.x());
    if (area > 0) return 1; // Против часовой стрелки
    if (area < 0) return -1; // По часовой стрелке
    return 0; // Коллинеарные
}

// Алгоритм Graham Scan
QList<Point> grahamScan(QList<Point>& points) {
    // Находим самую нижнюю точку
    int minIndex = 0;
    for (int i = 1; i < points.size(); i++) {
        if (points[i].y() < points[minIndex].y() ||
            (points[i].y() == points[minIndex].y() && points[i].x() < points[minIndex].x())) {
            minIndex = i;
        }
    }

    // Обмениваем самую нижнюю точку с первой
     std::swap(points[0], points[minIndex]);

    // Сортируем остальные точки по углу относительно самой нижней точки
    sort(points.begin() + 1, points.end(),
         bind(comparePoints, std::placeholders::_1, std::placeholders::_2, points[0]));

    // Алгоритм Graham Scan
    QList<Point> stack;
    stack.push_back(points[0]);
    stack.push_back(points[1]);
    stack.push_back(points[2]);

    for (int i = 3; i < points.size(); i++) {
        while (stack.size() >= 3 && ccw(stack[stack.size() - 2], stack.back(), points[i]) <= 0) {
            stack.pop_back();
        }
        stack.push_back(points[i]);
    }

    return stack;
}
