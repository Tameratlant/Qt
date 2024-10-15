#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QLineEdit>
#include <QLabel>
#include "polygon.h"
#include <QVBoxLayout>
#include <QWidget>
#include <QtGui>
#include <QColor>

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
    void on_okButton_clicked();

private:
    Ui::MainWindow *ui;
    int n = 0;
    QLineEdit* editN;
    QVBoxLayout* points_num_layout;
    Polygon polygon;
    QList<QLineEdit*> colorInputFields;
    QList<QLineEdit*> inputFields; // Список для хранения указателей на поля ввода
    QVBoxLayout* inputLayout; // Указатель на layout с полями ввода
    QVBoxLayout* edgesLayout;
    QVBoxLayout *edgesInputLayout;
    void createInputFields();
    void mousePressEvent(QMouseEvent *event);
    void drawPolygon();
    void paintEvent(QPaintEvent *event);
    void n_okButton_clicked();
    void showInputFields();
    void showEdgesSettings();
    void hideEdgesSettings();
    void hideInputFields();
};

#endif // MAINWINDOW_H
