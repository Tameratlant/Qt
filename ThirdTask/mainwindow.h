#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QLineEdit>
#include <QLabel>
#include "polygon.h"
#include <QVBoxLayout>

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
    Polygon polygon;
    QList<QLineEdit*> inputFields; // Список для хранения указателей на поля ввода
    QVBoxLayout* inputLayout; // Указатель на layout с полями ввода
    void createInputFields();
    void drawPolygon();
    void paintEvent(QPaintEvent *event);
};

#endif // MAINWINDOW_H
