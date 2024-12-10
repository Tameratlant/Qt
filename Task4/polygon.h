#ifndef POLYGON_H
#define POLYGON_H


class Polygon
{
public:
    int x;
    Polygon();


Polygon operator+(const Polygon& other) const {
    return Polygon();
}

// Перегрузка оператора -
Polygon operator-(const Polygon& other) const {
    return Polygon();
}
};
#endif // POLYGON_H
