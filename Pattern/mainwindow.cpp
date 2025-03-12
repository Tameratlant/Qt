#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    canvas = new Canvas(this);
    setCentralWidget(canvas);

    toolBar = new QToolBar(this);
    addToolBar(Qt::RightToolBarArea, toolBar);

    triangleButton = new QPushButton("Triangle", this);
    squareButton = new QPushButton("Square", this);
    circleButton = new QPushButton("Circle", this);

    toolBar->addWidget(triangleButton);
    toolBar->addWidget(squareButton);
    toolBar->addWidget(circleButton);

    setupParametersGroupBox(); // Настройка GroupBox с параметрами
    toolBar->addWidget(parametersGroupBox);

    connect(triangleButton, &QPushButton::clicked, this, &MainWindow::selectTriangle);
    connect(squareButton, &QPushButton::clicked, this, &MainWindow::selectSquare);
    connect(circleButton, &QPushButton::clicked, this, &MainWindow::selectCircle);

    // Соединяем слайдеры с обновлением параметров
    connect(widthSlider, &QSlider::valueChanged, this, &MainWindow::updateShapeParameters);
    connect(heightSlider, &QSlider::valueChanged, this, &MainWindow::updateShapeParameters);
    connect(rotationSlider, &QSlider::valueChanged, this, &MainWindow::updateShapeParameters);
}

MainWindow::~MainWindow()
{
}

void MainWindow::selectTriangle()
{
    canvas->setShapeType(1); // 1 for Triangle
    parametersGroupBox->setVisible(true); // Показываем GroupBox
}

void MainWindow::selectSquare()
{
    canvas->setShapeType(2); // 2 for Square
    parametersGroupBox->setVisible(true); // Показываем GroupBox
}

void MainWindow::selectCircle()
{
    canvas->setShapeType(3); // 3 for Circle
    parametersGroupBox->setVisible(true); // Показываем GroupBox
}

void MainWindow::setupParametersGroupBox()
{
    parametersGroupBox = new QGroupBox("Shape Parameters", this);
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

    layout->addWidget(new QLabel("Width:"));
    layout->addWidget(widthSlider);
    layout->addWidget(new QLabel("Height:"));
    layout->addWidget(heightSlider);
    layout->addWidget(new QLabel("Rotation:"));
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
