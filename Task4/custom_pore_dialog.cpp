#include "custom_pore_dialog.h"
#include "ui_custom_pore_dialog.h"

custom_pore_dialog::custom_pore_dialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::custom_pore_dialog)
{
    ui->setupUi(this);
}

custom_pore_dialog::~custom_pore_dialog()
{
    delete ui;
}

QString custom_pore_dialog::inputValue() const
{
    return ui->lineEdit->text(); // Предполагается, что в диалоговом окне есть LineEdit с именем lineEdit
}


