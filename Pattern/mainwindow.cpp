#include "mainwindow.h"
#include "qlabel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    canvas = new Canvas(this);
    setCentralWidget(canvas);

    toolBar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea, toolBar);

    createShapeButtons(); // Создаем кнопки для фигур
    setupParametersGroupBox(); // Настройка GroupBox с параметрами
    toolBar->addWidget(parametersGroupBox);

    // Соединяем слайдеры с обновлением параметров
    connect(widthSlider, &QSlider::valueChanged, this, &MainWindow::updateShapeParameters);
    connect(heightSlider, &QSlider::valueChanged, this, &MainWindow::updateShapeParameters);
    connect(rotationSlider, &QSlider::valueChanged, this, &MainWindow::updateShapeParameters);
}

MainWindow::~MainWindow()
{
}

void MainWindow::createShapeButtons()
{
    // Получаем количество элементов в enum (исключая Unknown)
    int shapeCount = static_cast<int>(ShapeType::Unknown);

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
    // Преобразуем индекс в ShapeType
    ShapeType type = static_cast<ShapeType>(index);
    canvas->setShapeType(type); // Устанавливаем тип фигуры
    parametersGroupBox->setVisible(true); // Показываем GroupBox
    toolBar->updateGeometry(); // Обновляем геометрию тулбара
}

void MainWindow::setupParametersGroupBox()
{
    parametersGroupBox = new QGroupBox("Параметры фигуры", this);
    QVBoxLayout *layout = new QVBoxLayout;

    widthSlider = new QSlider(Qt::Horizontal, this);
    widthSlider->setRange(10, 500); // Минимальная и максимальная ширина
    widthSlider->setValue(100); // Начальное значение

    heightSlider = new QSlider(Qt::Horizontal, this);
    heightSlider->setRange(10, 500); // Минимальная и максимальная высота
    heightSlider->setValue(100); // Начальное значение

    rotationSlider = new QSlider(Qt::Horizontal, this);
    rotationSlider->setRange(0, 360); // Угол поворота от 0 до 360 градусов
    rotationSlider->setValue(0); // Начальное значение

    layout->addWidget(new QLabel("Ширина:"));
    layout->addWidget(widthSlider);
    layout->addWidget(new QLabel("Высота:"));
    layout->addWidget(heightSlider);
    layout->addWidget(new QLabel("Поворот:"));
    layout->addWidget(rotationSlider);

    parametersGroupBox->setLayout(layout);
    parametersGroupBox->setVisible(true); // По умолчанию скрыт
}

void MainWindow::updateShapeParameters()
{
    int width = widthSlider->value();
    int height = heightSlider->value();
    int rotation = rotationSlider->value();

    canvas->setShapeSize(width, height);
    canvas->setShapeRotation(rotation);
}
