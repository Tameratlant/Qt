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
    //ui->comboBox->addItem("Треугольник");
    //ui->comboBox->addItem("Круг");

    ui->comboBox_2->addItem("Зеленый");
    ui->comboBox_2->addItem("Красный");

    ui->comboBox_3->addItem("Сплошная");
    ui->comboBox_3->addItem("Пунктирная");

    ui->comboBox_4->addItem("Сплошная штриховка");
    ui->comboBox_4->addItem("Диагональная штриховка");

    figureLabel = new QLabel(this);
    figureLabel->setGeometry(50, 50, 500, 500);

    //connect(comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Media::onComboBoxIndexChanged);
    //connect(comboBox_2, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Media::updateFigure);
    //connect(comboBox_3, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Media::updateFigure);
    //connect(comboBox_4, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Media::updateFigure);


    //comboBox = ui->comboBox;
    comboBox = new QComboBox(this);
    comboBox->addItem("Треугольник");
    comboBox->addItem("Треугольник1");
    connect(comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Media::onComboBoxIndexChanged);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(comboBox);

    //QVBoxLayout *layout2 = new QVBoxLayout(this);
    layout->addWidget(&label);
    onComboBoxIndexChanged(0);
    //updateFigure();
}

Media::~Media()
{
    delete ui;
}

void Media::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::green);

    if (shape == "Круг") {
        painter.drawEllipse(rect().center(), rect().width() / 2, rect().height() / 2);
    } else if (shape == "Квадрат") {
        painter.drawRect(rect());
    }




    /*
    QPainter painter(this);

    // Определяем параметры фигуры на основе выбранных значений
    QColor color;
    Qt::PenStyle penStyle;
    Qt::BrushStyle brushStyle;

    QPolygon triangle;
    triangle << QPoint(50, 10) << QPoint(10, 50) << QPoint(10, 10);
    painter.drawPolygon(triangle);

    switch (comboBox_2->currentIndex()) {
        case 0:
            color = Qt::green;
            break;
        // ... другие цвета
    }

    switch (comboBox_3->currentIndex()) {
        case 0:
            penStyle = Qt::SolidLine;
            break;
        case 1:
            penStyle = Qt::DashLine;
            break;
        // ... другие стили линий
    }

    switch (comboBox_4->currentIndex()) {
        case 0:
            brushStyle = Qt::SolidPattern;
            break;
        case 1:
            brushStyle = Qt::DiagCrossPattern;
            break;
        // ... другие стили заливки
    }

    QPen pen(color, 2, penStyle);
    QBrush brush(color, brushStyle);
    painter.setPen(pen);
    painter.setBrush(brush);

    // Рисуем фигуру в зависимости от выбранного типа
    switch (comboBox->currentIndex()) {
        case 0: // Треугольник
    {
            QPolygon triangle;
            triangle << QPoint(50, 10) << QPoint(10, 50) << QPoint(10, 10);
            painter.drawPolygon(triangle);
            break;
    }
        case 1: // Круг
    {
            painter.drawEllipse(500, 500, 500, 500);
            break;
        // ... другие фигуры
    }
    }
    */
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

