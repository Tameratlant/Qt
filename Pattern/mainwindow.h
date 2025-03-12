#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QPushButton>
#include <QGroupBox>
#include <QSlider>
#include <QLabel>
#include <QVBoxLayout>
#include "canvas.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void selectTriangle();
    void selectSquare();
    void selectCircle();
    void updateShapeParameters();

private:
    Canvas *canvas;
    QToolBar *toolBar;
    QPushButton *triangleButton;
    QPushButton *squareButton;
    QPushButton *circleButton;

    QGroupBox *parametersGroupBox;
    QSlider *widthSlider;
    QSlider *heightSlider;
    QSlider *rotationSlider;

    void setupParametersGroupBox();
};

#endif // MAINWINDOW_H
