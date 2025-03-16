#ifndef SHAPE_TYPES_H
#define SHAPE_TYPES_H

#include <QString>

enum class ShapeType {
    eleptic_pore,
    custom_pore,
    simple_fissure,
    thin_fissure,
    unknown   // Неизвестный тип (для обработки ошибок)
};

QString enum_to_string(ShapeType type);

#endif // SHAPE_TYPES_H
