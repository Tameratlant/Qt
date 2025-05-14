#include "settings.h"
#include "qboxlayout.h"
#include <QLabel>
#include <QSlider>
#include <QLineEdit>
#include "shape_types.h"

QVBoxLayout *settings::get_layout()
{
    QVBoxLayout *layout = new QVBoxLayout;

    if (type == ShapeType::simple_fissure) {

        auto width_line = new QLineEdit();
        //width_line->setRange(10, 500); // Минимальная и максимальная ширина
        //width_line->setValue(100); // Начальное значение

        auto lenght_line = new QLineEdit();


        auto rotationSlider = new QSlider(Qt::Horizontal);
        rotationSlider->setRange(0, 360); // Угол поворота от 0 до 360 градусов
        rotationSlider->setValue(0); // Начальное значение

        layout->addWidget(new QLabel("Ширина:"));
        layout->addWidget(width_line);
        layout->addWidget(new QLabel("Длина:"));
        layout->addWidget(lenght_line);
        layout->addWidget(new QLabel("Поворот:"));
        layout->addWidget(rotationSlider);

    }
    return layout;
}

