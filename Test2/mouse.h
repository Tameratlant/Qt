#ifndef MOUSE_H
#define MOUSE_H

#include <QWidget>

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
};

#endif // MOUSE_H
