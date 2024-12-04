#ifndef MEDIA_H
#define MEDIA_H

#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QPainter>
#include <QColor>
#include <QPen>
#include <QBrush>
#include <QVBoxLayout>

namespace Ui {
class Media;
}

class Media : public QWidget
{
    Q_OBJECT
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QComboBox *shapeComboBox;
    QComboBox *colorComboBox;
    QComboBox *borderComboBox;
    QComboBox *brushComboBox;
    QLabel *figureLabel;


public:
    explicit Media(QWidget *parent = nullptr);
    void updateFigure();
    void paintEvent(QPaintEvent *event);
    void onComboBoxIndexChanged(int index);
    void onShapeChanged(int index);
    void onColorChanged(int index);
    void onGutsChanged(int index);
    void onBorderChanged(int index);
    QLabel label;
    QString shape = "Круг";
    Qt::GlobalColor color = Qt::red;
    Qt::GlobalColor borderColor = Qt::red;
    Qt::BrushStyle brush = Qt::NoBrush;
    ~Media();

private:
    Ui::Media *ui;
};



#endif // MEDIA_H
