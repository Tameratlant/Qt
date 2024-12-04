#ifndef CUSTOM_PORE_DIALOG_H
#define CUSTOM_PORE_DIALOG_H

#include <QWidget>

namespace Ui {
class custom_pore_dialog;
}

class custom_pore_dialog : public QWidget
{
    Q_OBJECT

public:
    explicit custom_pore_dialog(QWidget *parent = nullptr);
    QString inputValue() const;
    ~custom_pore_dialog();

private:
    Ui::custom_pore_dialog *ui;
};

#endif // CUSTOM_PORE_DIALOG_H
