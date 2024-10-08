#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QtGui>

#include <mousewindow.h>
#include <multimediawindow.h>

#define APP_NAME "TASK 2"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  void setup_MainWindow();

  Ui::MainWindow *ui;
  MouseWindow  *mouseHandler;
  MultimediaWindow    *multimedia;

private slots:
  void show_MouseHandler() const;
  void show_Multimedia() const;
};
#endif // MAIN_WINDOW_H
