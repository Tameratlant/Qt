#ifndef MOUSE_H
#define MOUSE_H

#include <QWidget>
#include <QtGui>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class Mouse;
}
QT_END_NAMESPACE

class Mouse : public QWidget {
  Q_OBJECT

public:
  Mouse(QWidget *parent = nullptr);
  ~Mouse();

private:

  Ui::Mouse *ui;

protected:

  void mouseMoveEvent(QMouseEvent *event) override;
  void mousePressEvent(QMouseEvent *event) override;

  void paintEvent(QPaintEvent *event) override;

};
#endif // __mousehandler_hpp_
