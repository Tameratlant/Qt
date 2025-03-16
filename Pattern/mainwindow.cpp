#include "mainwindow.h"
#include "qlabel.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    canvas = new Canvas(this);
    setCentralWidget(canvas);

    toolBar = new QToolBar(this);
    addToolBar(Qt::RightToolBarArea, toolBar);

    createShapeButtons(); // Создаем кнопки для фигур
    setupParametersGroupBox(ShapeType::unknown); // Настройка GroupBox с параметрами
    toolBar->addWidget(parametersGroupBox);


}

MainWindow::~MainWindow()
{
}

void MainWindow::createShapeButtons()
{
    // Получаем количество элементов в enum (исключая Unknown)
    int shapeCount = static_cast<int>(ShapeType::unknown);

    for (int i = 0; i < shapeCount; ++i) {
        ShapeType type = static_cast<ShapeType>(i);
        QString buttonText = enum_to_string(type); // Название фигуры на кириллице

        QPushButton *button = new QPushButton(buttonText, this);
        shapeButtons.append(button);
        toolBar->addWidget(button);

        // Подключаем кнопку к слоту handleButtonClick с параметром (индекс кнопки)
        connect(button, &QPushButton::clicked, this, [this, i]() { handleButtonClick(i); });
    }
}

void MainWindow::handleButtonClick(int index)
{
    parametersGroupBox->setVisible(false); // Показываем GroupBox
    //delete(parametersGroupBox);
    // Преобразуем индекс в ShapeType
    setupParametersGroupBox(static_cast<ShapeType>(index));
    canvas->setShapeType(static_cast<ShapeType>(index)); // Устанавливаем тип фигуры
    parametersGroupBox->setVisible(true); // Показываем GroupBox
    toolBar->updateGeometry(); // Обновляем геометрию тулбара
}

void MainWindow::setupParametersGroupBox(ShapeType type)
{
    parametersGroupBox =new QGroupBox("Параметры ", this);
    parametersGroupBox->setGeometry(800, 120, 100, 300);
        //ui->figure_settings;//
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

    if (type == ShapeType::thin_fissure)
    {

        lenghttSlider = new QSlider(Qt::Horizontal, this);
        lenghttSlider->setRange(10, 500); // Минимальная и максимальная высота
        lenghttSlider->setValue(100); // Начальное значение

        rotationSlider = new QSlider(Qt::Horizontal, this);
        rotationSlider->setRange(0, 360); // Угол поворота от 0 до 360 градусов
        rotationSlider->setValue(0); // Начальное значение

        layout->addWidget(new QLabel("Высота:"));
        layout->addWidget(lenghttSlider);
        layout->addWidget(new QLabel("Поворот:"));
        layout->addWidget(rotationSlider);

        // Соединяем слайдеры с обновлением параметров
        connect(lenghttSlider, &QSlider::valueChanged, this, &MainWindow::updateShapeParameters);
        connect(rotationSlider, &QSlider::valueChanged, this, &MainWindow::updateShapeParameters);
    }






    parametersGroupBox->setLayout(layout);
    parametersGroupBox->setVisible(false); // По умолчанию скрыт


}

void MainWindow::updateShapeParameters()
{
    int width = widthSlider->value();
    int lenght = lenghttSlider->value();
    int rotation = rotationSlider->value();

    canvas->setShapeSize(width, lenght);
    canvas->setShapeRotation(rotation);
}
