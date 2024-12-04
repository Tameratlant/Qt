#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QMouseEvent>
#include <QComboBox>
#include <QLineEdit>
#include <QDialog>
class custom_pore_dialog;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class AddFigureDialog : public QDialog {
    Q_OBJECT
public:
    //explicit AddFigureDialog(QWidget *parent = nullptr);
    //~AddFigureDialog() override;

private:
    //Ui::AddFigureDialog *ui;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    void custom_pore_dialog_open ();

private slots:

    //void on_pushButton_clicked();
    //void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    custom_pore_dialog *input_dialog = nullptr;
    //void paintEvent(QPaintEvent *event) override;
    void drawShape(QString shape, double density);
};
#endif // MAINWINDOW_H
