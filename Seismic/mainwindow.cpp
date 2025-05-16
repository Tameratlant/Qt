#include "mainwindow.h"
#include "qlabel.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPoint>
#include <QList>
#include <fstream>
#include <vector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    canvas = new Canvas(this);
    setCentralWidget(canvas);

    toolBar = new QToolBar(this);
    addToolBar(Qt::RightToolBarArea, toolBar);

    createShapeButtons();
    setupParametersGroupBox(ShapeType::unknown);
    toolBar->addWidget(parametersGroupBox);
}

MainWindow::~MainWindow()
{
}

void MainWindow::createShapeButtons()
{
    int shapeCount = static_cast<int>(ShapeType::unknown);

    for (int i = 0; i < shapeCount; ++i) {
        ShapeType type = static_cast<ShapeType>(i);
        QString buttonText = enum_to_string(type);

        QPushButton *button = new QPushButton(buttonText, this);
        shapeButtons.append(button);
        toolBar->addWidget(button);

        connect(button, &QPushButton::clicked, this, [this, i]() { handleButtonClick(i); });
    }
}

void MainWindow::handleButtonClick(int index)
{
    parametersGroupBox->setVisible(false);
    setupParametersGroupBox(static_cast<ShapeType>(index));
    canvas->setShapeType(static_cast<ShapeType>(index));
    parametersGroupBox->setVisible(true);
    toolBar->updateGeometry();
}

void MainWindow::setupParametersGroupBox(ShapeType type)
{
    parametersGroupBox =new QGroupBox("Параметры ", this);
    parametersGroupBox->setGeometry(800, 120, 100, 300);
        //ui->figure_settings;//
    QVBoxLayout *layout = new QVBoxLayout;

    if (type == ShapeType::simple_fissure) {

        width_line = new QLineEdit(this);
        lenght_line = new QLineEdit(this);
        layout->addWidget(new QLabel("Ширина:"));
        layout->addWidget(width_line);
        layout->addWidget(new QLabel("Длина:"));
        layout->addWidget(lenght_line);

        connect(width_line, &QLineEdit::textChanged, this, [this, type]() { MainWindow::updateShapeParameters(type); });
        connect(lenght_line, &QLineEdit::textChanged, this, [this, type]() { MainWindow::updateShapeParameters(type); });

    }
    else if (type == ShapeType::thin_fissure) {

        width_line = nullptr;
        lenght_line = new QLineEdit(this);

        layout->addWidget(new QLabel("Длина:"));
        layout->addWidget(lenght_line);
        connect(lenght_line, &QLineEdit::textChanged, this, [this, type]() { MainWindow::updateShapeParameters(type); });
    }
    else if (type == ShapeType::eleptic_pore) {


        width_line = new QLineEdit(this);
        lenght_line = new QLineEdit(this);

        layout->addWidget(new QLabel("b:"));
        layout->addWidget(width_line);
        layout->addWidget(new QLabel("a:"));
        layout->addWidget(lenght_line);

        connect(lenght_line, &QLineEdit::textChanged, this, [this, type]() { MainWindow::updateShapeParameters(type); });
    }
    rotationSlider = new QSlider(Qt::Horizontal, this);
    rotationSlider->setRange(0, 360);
    rotationSlider->setValue(0);
    pos_x_line = new QLineEdit(this);
    pos_y_line = new QLineEdit(this);
    connect(rotationSlider, &QSlider::valueChanged, this, [this, type]() { MainWindow::updateShapeParameters(type); });
    connect(pos_x_line, &QLineEdit::textChanged, this, [this, type]() { MainWindow::updateShapeParameters(type); });
    connect(pos_y_line, &QLineEdit::textChanged, this, [this, type]() { MainWindow::updateShapeParameters(type); });

    layout->addWidget(new QLabel("Поворот:"));
    layout->addWidget(rotationSlider);
    layout->addWidget(new QLabel("X:"));
    layout->addWidget(pos_x_line);
    layout->addWidget(new QLabel("Y:"));
    layout->addWidget(pos_y_line);

    parametersGroupBox->setLayout(layout);
    parametersGroupBox->setVisible(false);


}

void MainWindow::updateShapeParameters(ShapeType type)
{
    bool ok = 1;
    int width, lenght;
    QPoint pos(0, 0);
    /*
    int tmp = lenght_line->text().toInt(&ok);
    if (ok) {
        lenght = tmp;
    } else {
        QMessageBox::warning(this, "Ошибка", "Некорректный ввод");
        return;
    }

    if (type != ShapeType::thin_fissure)
    {
        tmp = width_line->text().toInt(&ok);
        if (ok) {
            width = tmp;
        } else {
            QMessageBox::warning(this, "Ошибка", "Некорректный ввод");
            return;
        }
    }
    */

    lenght = lenght_line->text().toInt(&ok);
    if (type != ShapeType::thin_fissure)
        width = width_line->text().toInt(&ok);
    else
        width = 1;

    int rotation = rotationSlider->value();
    pos.setX(pos_x_line->text().toInt(&ok));
    pos.setY(pos_y_line->text().toInt(&ok));
    canvas->setShapeSize(width, lenght);
    canvas->setShapeRotation(rotation);
    canvas->setPos(pos);
}

void writePointsToBinaryFiles(const QList<QPoint>& points) {
    // Prepare data vectors
    std::vector<float> x_coords;
    std::vector<float> y_coords;
    std::vector<float> z_coords;

    x_coords.reserve(points.size());
    y_coords.reserve(points.size());
    z_coords.reserve(points.size());

    for (const QPoint& point : points) {
        x_coords.push_back(static_cast<float>(point.x()));
        y_coords.push_back(static_cast<float>(point.y()));
        z_coords.push_back(0.0f); // z is always 0
    }
    std::ofstream x_file("x.bin", std::ios::binary);
    std::ofstream y_file("y.bin", std::ios::binary);
    std::ofstream z_file("z.bin", std::ios::binary);

    x_file.write(reinterpret_cast<const char*>(x_coords.data()), x_coords.size() * sizeof(float));
    y_file.write(reinterpret_cast<const char*>(y_coords.data()), y_coords.size() * sizeof(float));
    z_file.write(reinterpret_cast<const char*>(z_coords.data()), z_coords.size() * sizeof(float));
}
