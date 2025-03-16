#include "settings.h"
#include "qboxlayout.h"
#include "qslider.h"
#include "shape_types.h"
/*
QVBoxLayout settings::get_layout()
{
    QVBoxLayout *layout = new QVBoxLayout;

    if (type == ShapeType::simple_fissure) {

        widthSlider = new QSlider(Qt::Horizontal, this);
        widthSlider->setRange(10, 500); // Минимальная и максимальная ширина
        widthSlider->setValue(100); // Начальное значение

        lenghttSlider = new QSlider(Qt::Horizontal, this);
        lenghttSlider->setRange(10, 500); // Минимальная и максимальная высота
        lenghttSlider->setValue(100); // Начальное значение

        rotationSlider = new QSlider(Qt::Horizontal, this);
        rotationSlider->setRange(0, 360); // Угол поворота от 0 до 360 градусов
        rotationSlider->setValue(0); // Начальное значение

        layout->addWidget(new QLabel("Ширина:"));
        layout->addWidget(widthSlider);
        layout->addWidget(new QLabel("Высота:"));
        layout->addWidget(lenghttSlider);
        layout->addWidget(new QLabel("Поворот:"));
        layout->addWidget(rotationSlider);

        // Соединяем слайдеры с обновлением параметров
        connect(widthSlider, &QSlider::valueChanged, this, &MainWindow::updateShapeParameters);
        connect(lenghttSlider, &QSlider::valueChanged, this, &MainWindow::updateShapeParameters);
        connect(rotationSlider, &QSlider::valueChanged, this, &MainWindow::updateShapeParameters);
    }

}
*/
