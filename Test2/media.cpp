#include "media.h"
#include "ui_media.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
Media::Media(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Media)
{
    ui->setupUi(this);
    setFocusPolicy(Qt::StrongFocus);
    /*
    ui->comboBox->addItem("Треугольник");
    ui->comboBox->addItem("Круг");

    ui->comboBox_2->addItem("Зеленый");
    ui->comboBox_2->addItem("Красный");

    ui->comboBox_3->addItem("Сплошная");
    ui->comboBox_3->addItem("Пунктирная");

    ui->comboBox_4->addItem("Сплошная штриховка");
    ui->comboBox_4->addItem("Диагональная штриховка");

    figureLabel = new QLabel(this);
    figureLabel->setGeometry(50, 50, 500, 500);
    QWidget *parentWidget1 = new QWidget;
    QWidget *parentWidget2 = new QWidget;
    //connect(comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Media::onComboBoxIndexChanged);
    //connect(comboBox_2, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Media::updateFigure);
    //connect(comboBox_3, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Media::updateFigure);
    //connect(comboBox_4, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Media::updateFigure);


    //comboBox = ui->comboBox;
    comboBox = new QComboBox(this);
    */
    shapeComboBox = ui->comboBox;
    shapeComboBox->addItem("Круг");
    shapeComboBox->addItem("Квадрат");
    shapeComboBox->addItem("Треугольник");

    colorComboBox = ui->comboBox_2;
    colorComboBox->addItem("Красный");
    colorComboBox->addItem("Зеленый");
    colorComboBox->addItem("Синий");

    borderComboBox = ui->comboBox_3;
    borderComboBox->addItem("Красный");
    borderComboBox->addItem("Зеленый");
    borderComboBox->addItem("Синий");

    brushComboBox = ui->comboBox_4;
    brushComboBox->addItem("Сплошная");
    brushComboBox->addItem("Горизонтальная");
    brushComboBox->addItem("Вертикальная");

    // Подключаем сигналы к слотам
    connect(shapeComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Media::onShapeChanged);
    connect(colorComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Media::onColorChanged);
    connect(borderComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Media::onBorderChanged);
    connect(brushComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Media::onGutsChanged);

    // Устанавливаем layout
    QHBoxLayout *topLayout = new QHBoxLayout;
    //topLayout->addWidget(shapeComboBox);
    //topLayout->addWidget(colorComboBox);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(topLayout);

    // Начальные значения
    onShapeChanged(0);
    onColorChanged(0);
    onBorderChanged(0);
    onGutsChanged(0);

    //resize(300, 200);
}

Media::~Media()
{
    delete ui;
}

void Media::paintEvent(QPaintEvent *event) {
        QPainter painter(this);
        painter.setPen(borderColor);
        QPen pen(borderColor, 3);
        painter.setPen(pen);
        painter.setBrush(color);
        // Получаем центр окна
        int centerX = width() / 2;
        int centerY = height() / 2;

        // Рисуем фигуру
        if (shape == "Круг") {
            painter.setBrush(Qt::BrushStyle(brush));
            painter.setBrush(color);
            painter.drawEllipse(centerX - 50, centerY - 50, 100, 100);
        } else if (shape == "Квадрат") {
            painter.setBrush(Qt::BrushStyle(brush));
            painter.setBrush(color);
            painter.drawRect(centerX - 50, centerY - 50, 100, 100);
        } else if (shape == "Треугольник") {
            // Рисуем треугольник
            QPolygonF triangle;
            triangle << QPointF(centerX, centerY - 50) // Вершина
                    << QPointF(centerX - 50, centerY + 50) // Левая нижняя вершина
                    << QPointF(centerX + 50, centerY + 50); // Правая нижняя вершина
            painter.setBrush(Qt::BrushStyle(brush));
            painter.setBrush(color);
            painter.drawPolygon(triangle);
        }
    }

void Media::updateFigure()
{
    // Обновление параметров фигуры на основе выбранных значений
    // ...

    //update();
    qDebug() << "Изменился индекс: " << 1;
}

void Media::onComboBoxIndexChanged(int index) {
        if (index == 0) {
            shape = "Круг";
        } else if (index == 1) {
            shape = "Квадрат";
        }
        update(); // Перерисовываем виджет
    }

void Media::onShapeChanged(int index) {
    if (index == 0) {
        shape = "Круг";
    } else if (index == 1) {
        shape = "Квадрат";
    } else if (index == 2) {
        shape = "Треугольник";
    }
    update();
}

void Media::onColorChanged(int index) {
    if (index == 0) {
        color = Qt::red;
    } else if (index == 1) {
        color = Qt::green;
    } else if (index == 2) {
        color = Qt::blue;
    }
    update();
}

void Media::onBorderChanged(int index) {
    if (index == 0) {
        borderColor = Qt::red;
    } else if (index == 1) {
        borderColor = Qt::green;
    } else if (index == 2) {
        borderColor = Qt::blue;
    }
    update();
}

void Media::onGutsChanged(int index) {
    if (index == 0) {
        brush = Qt::SolidPattern;
    } else if (index == 1) {
        brush = Qt::HorPattern;
    } else if (index == 2) {
        brush = Qt::VerPattern;
    }
    update();
}

