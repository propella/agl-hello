// main.cpp

#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel label("Hello, World!");
    label.setWindowFlags(Qt::FramelessWindowHint);
    label.show();
    return a.exec();
}
