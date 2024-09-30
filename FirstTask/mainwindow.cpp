
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QDateTime>
#include <QFile>
#include <QTextStream>

class MyWidget : public QWidget {
public:
    MyWidget(QWidget *parent = nullptr) : QWidget(parent) {
        lineEdit1 = new QLineEdit;
        lineEdit2 = new QLineEdit;
        lineEdit2->setReadOnly(true);
        button = new QPushButton("Отправить");
        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(lineEdit1);
        layout->addWidget(lineEdit2);
        layout->addWidget(button);
        setLayout(layout);
        connect(button, &QPushButton::clicked, this, &MyWidget::onButtonClicked);
    }

private slots:
    void onButtonClicked() {
        lineEdit2->setText(lineEdit1->text());

        // Логгировние
        QDateTime currentDateTime = QDateTime::currentDateTime();
        QString dateTimeString = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");
        QString logMessage = dateTimeString + " - " + lineEdit1->text();

        QFile file("log.txt");
        if (file.open(QIODevice::Append)) {
            QTextStream out(&file);
            out << logMessage << endl;
            file.close();
        }
    }
private:
    QLineEdit *lineEdit1, *lineEdit2;
    QPushButton *button;
};
