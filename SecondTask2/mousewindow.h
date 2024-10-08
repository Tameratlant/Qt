#ifndef MOUSE_WINDOW_H
#define MOUSE_WINDOW_H

#include <QWidget>
#include <QtGui>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class MouseWindow;
}
QT_END_NAMESPACE

class MouseWindow : public QWidget {
  Q_OBJECT

public:
  MouseWindow(QWidget *parent = nullptr);
  ~MouseWindow();

private:

  Ui::MouseWindow *ui;

protected:

  void mouseMoveEvent(QMouseEvent *event) override;
  void mousePressEvent(QMouseEvent *event) override;

  void paintEvent(QPaintEvent *event) override;

};
#endif // MOUSE_WINDOW_H
