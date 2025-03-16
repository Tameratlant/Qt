#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QPushButton>
#include <QGroupBox>
#include <QSlider>
#include <QLineEdit>>
#include <QVBoxLayout>
#include "canvas.h"
#include "shape_types.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

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
    Ui::MainWindow *ui;
    Canvas *canvas;
    QToolBar *toolBar;
    QList<QPushButton*> shapeButtons; // Список кнопок для фигур

    QGroupBox *parametersGroupBox;
    QLineEdit *width_line;
    QLineEdit *lenght_line;
    QLineEdit *eleptic_a_line;
    QLineEdit *eleptic_e_line;
    QSlider *rotationSlider;

    void setupParametersGroupBox(ShapeType type);
    void createShapeButtons(); // Создание кнопок на основе enum
};

#endif // MAINWINDOW_H
