#include "mouse.h"
#include "ui_mouse.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

Mouse::Mouse(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mouse)
{
    ui->setupUi(this);
    setFocusPolicy(Qt::StrongFocus);

    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    //ui->label->setFixedSize(30, 10);
    ui->label_2->setAttribute(Qt::WA_TransparentForMouseEvents);
    //ui->label_2->setFixedSize(30, 10);
    ui->label_3->setAttribute(Qt::WA_TransparentForMouseEvents);
    //ui->label_2->setFixedSize(50, 10);
    ui->realtime_lineEdit->setAttribute(Qt::WA_TransparentForMouseEvents);
    //ui->realtime_lineEdit->setGeometry(200, 200, 50, 20);
    ui->static_lineEdit->setAttribute(Qt::WA_TransparentForMouseEvents);
    //ui->static_lineEdit->setFixedSize(200, 20);
    setMouseTracking(true);
}

Mouse::~Mouse()
{
    delete ui;
}

void Mouse::mouseMoveEvent(QMouseEvent *event) {
  int x = event->pos().x();
  int y = height() - event->pos().y();
  ui->realtime_lineEdit->setText(QString("X: %1, Y: %2").arg(x).arg(y));
}

void Mouse::mousePressEvent(QMouseEvent *event) {
  qDebug() << "mousePressEvent";
  if (event->button() == Qt::LeftButton) {
    int x = event->pos().x();
    int y = height() - event->pos().y();

    ui->static_lineEdit->setText(QString("X: %1, Y: %2").arg(x).arg(y));
  }
}

void Mouse::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing, false);
  painter.setPen(palette().dark().color());
  painter.setBrush(Qt::NoBrush);
  painter.drawRect(QRect(0, 0, width() - 1, height() - 1));
}

