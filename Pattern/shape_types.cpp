#include "shape_types.h"

QString enum_to_string(ShapeType type) {
    switch (type) {
    case ShapeType::eleptic_pore:
        return "Элиптическая пора";
    case ShapeType::custom_pore:
        return "Квадрат";
    case ShapeType::simple_fissure:
        return "Круг";
    case ShapeType::thin_fissure:
        return "Круг";
    default:
        return "Неизвестная фигура";
    }
}
