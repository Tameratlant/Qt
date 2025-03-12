#include "shape_types.h"

QString enum_to_string(ShapeType type) {
    switch (type) {
    case ShapeType::Triangle:
        return "Треугольник";
    case ShapeType::Square:
        return "Квадрат";
    case ShapeType::Circle:
        return "Круг";
    default:
        return "Неизвестная фигура";
    }
}
