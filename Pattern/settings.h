#pragma once
#include "point.h"

class QVBoxLayout;
enum class ShapeType;
class QSlider;
struct settings{
    Point pos;
    int angle;
    ShapeType type;

    int wedth_or_a; //for simple fissure and elleptic pore
    int e; //for eleptic pore
    int lenght; //for fissure

    QSlider *widthSlider;
    QSlider *lenghttSlider;
    QSlider *rotationSlider;

    settings() = default;

    QVBoxLayout get_layout();
};
