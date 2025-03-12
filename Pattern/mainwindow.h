#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QPushButton>
#include <QGroupBox>
#include <QSlider>
#include <QVBoxLayout>
#include "canvas.h"
#include "shape_types.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleButtonClick(int index); // Слот для обработки нажатия кнопки
    void updateShapeParameters();

private:
    Canvas *canvas;
    QToolBar *toolBar;
    QList<QPushButton*> shapeButtons; // Список кнопок для фигур

    QGroupBox *parametersGroupBox;
    QSlider *widthSlider;
    QSlider *heightSlider;
    QSlider *rotationSlider;

    void setupParametersGroupBox();
    void createShapeButtons(); // Создание кнопок на основе enum
};

#endif // MAINWINDOW_H
