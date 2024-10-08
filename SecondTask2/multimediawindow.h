#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <QWidget>
#include <QComboBox>
#include <QLabel>

class SecondWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);

private:
    QComboBox *figureComboBox;
    QComboBox *colorComboBox;
    QComboBox *borderComboBox;
    QComboBox *fillComboBox;
    QLabel *figureLabel;

    void paintEvent(QPaintEvent *event) override;
    void updateFigure();
};

#endif // MULTIMEDIA_H
