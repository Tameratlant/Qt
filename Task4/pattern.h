#ifndef PATTERN_H
#define PATTERN_H
#include <iostream>
#include <optional>

class Pore;
class Irregularity;
class Pattern
{
public:
    Pattern(int _columns_num, int _row_num, double _shift, int x, int y) : columns_num(_columns_num), row_num(_row_num),
        size_x(x), size_y(y), shift(_shift) {}
    int columns_num;
    int row_num;
    int size_x, size_y;
    double shift;
    double rotate = 0;
    bool random_angle = 0;
    bool random_pos = 0;
    void draw(Irregularity irr) const;
};

#endif // PATTERN_H
