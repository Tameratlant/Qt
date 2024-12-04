#ifndef MOUSE_H
#define MOUSE_H

#include <QWidget>
#include <QtGui>
#include <QDebug>
namespace Ui {
class Mouse;
}

class Mouse : public QWidget
{
    Q_OBJECT

public:
    explicit Mouse(QWidget *parent = nullptr);
    ~Mouse();

private:
    Ui::Mouse *ui;

protected:

  void mouseMoveEvent(QMouseEvent *event) override;
  void mousePressEvent(QMouseEvent *event) override;

  void paintEvent(QPaintEvent *event) override;
};
#endif // MOUSE_H
