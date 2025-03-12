#ifndef SHAPE_TYPES_H
#define SHAPE_TYPES_H

#include <QString>

// Enum для типов фигур
enum class ShapeType {
    Triangle, // Треугольник
    Square,   // Квадрат
    Circle,   // Круг
    Unknown   // Неизвестный тип (для обработки ошибок)
};

// Функция для преобразования enum в строку (название фигуры на кириллице)
QString enum_to_string(ShapeType type);

#endif // SHAPE_TYPES_H
