#include "mainwindow.h"
#include "qlabel.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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

        width_line = new QLineEdit(this);
        lenght_line = new QLineEdit(this);
        layout->addWidget(new QLabel("Ширина:"));
        layout->addWidget(width_line);
        layout->addWidget(new QLabel("Длина:"));
        layout->addWidget(lenght_line);

        // Соединяем слайдеры с обновлением параметров

        connect(width_line, &QLineEdit::textChanged, this, [this, type]() { MainWindow::updateShapeParameters(type); });
        connect(lenght_line, &QLineEdit::textChanged, this, [this, type]() { MainWindow::updateShapeParameters(type); });

    }
    else if (type == ShapeType::thin_fissure) {

        width_line = nullptr;
        lenght_line = new QLineEdit(this);

        layout->addWidget(new QLabel("Длина:"));
        layout->addWidget(lenght_line);


        // Соединяем слайдеры с обновлением параметров
        connect(lenght_line, &QLineEdit::textChanged, this, [this, type]() { MainWindow::updateShapeParameters(type); });
    }
    else if (type == ShapeType::eleptic_pore) {


        width_line = new QLineEdit(this);
        lenght_line = new QLineEdit(this);

        layout->addWidget(new QLabel("Малая полуось:"));
        layout->addWidget(width_line);
        layout->addWidget(new QLabel("Большая полуось:"));
        layout->addWidget(lenght_line);

        // Соединяем слайдеры с обновлением параметров
        connect(lenght_line, &QLineEdit::textChanged, this, [this, type]() { MainWindow::updateShapeParameters(type); });
    }
    rotationSlider = new QSlider(Qt::Horizontal, this);
    rotationSlider->setRange(0, 360); // Угол поворота от 0 до 360 градусов
    rotationSlider->setValue(0); // Начальное значение
    connect(rotationSlider, &QSlider::valueChanged, this, [this, type]() { MainWindow::updateShapeParameters(type); });
    layout->addWidget(new QLabel("Поворот:"));
    layout->addWidget(rotationSlider);
    /*
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
*/
    parametersGroupBox->setLayout(layout);
    parametersGroupBox->setVisible(false); // По умолчанию скрыт


}

// Считываем данные из полей ввода и добавляем точки в полигон


void MainWindow::updateShapeParameters(ShapeType type)
{
    bool ok = 1;
    int width, lenght;
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

    canvas->setShapeSize(width, lenght);
    canvas->setShapeRotation(rotation);
}
