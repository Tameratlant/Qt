#pragma once
#include "point.h"

struct settings{
    Point pos;
    int angle;

    int wedth_or_a; //for simple fissure and elleptic pore
    int e; //for eleptic pore
    int lenght; //for fissure

    settings() = default;
};
