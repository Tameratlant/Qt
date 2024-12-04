#ifndef IRREGULARITY_H
#define IRREGULARITY_H

class Polygon;

class Irregularity
{
public:
    Irregularity(int _x, int _y) : x(_x), y(_y) {}
    Irregularity() {}
    double x,y;
    virtual void draw(int x, int y) {
        return;
    }

};

class Pore : public Irregularity {
public:
    Pore(int _a, int _b, int _x, int _y) : Irregularity(_x,_y), a(_a), b(_b) {}
    double density;
    double a, b;    //large and small axes of elipse

};

class Custom_pore : public Irregularity {
public:
    double density;
    Polygon *poly;
    Custom_pore(Polygon *_poly) : Irregularity(), poly(_poly) {}
};

class Fissure : public Irregularity {
public:
    double density;
    Polygon *poly;
    Fissure(Polygon *_poly) : Irregularity(), poly(_poly) {}
};
#endif // IRREGULARITY_H
