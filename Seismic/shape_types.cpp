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

int get_num_of_point_to_approx(ShapeType shape)
{
    switch (shape){
    case ShapeType::eleptic_pore: return 10;
    case ShapeType::custom_pore: return 10;
    case ShapeType::simple_fissure: return 4;
    case ShapeType::thin_fissure: return 2;
    case ShapeType::unknown: break;
    }
    return 0;
}
