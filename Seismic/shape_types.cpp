#include "shape_types.h"

QString enum_to_string(ShapeType type) {
    switch (type) {
    case ShapeType::eleptic_pore:
        return "Элиптическая пора";
    case ShapeType::custom_pore:
        return "Кастомная пора";
    case ShapeType::simple_fissure:
        return "Трещина";
    case ShapeType::thin_fissure:
        return "Тонкая трещина";
    default:
        return "Неизвестная фигура";
    }
}
