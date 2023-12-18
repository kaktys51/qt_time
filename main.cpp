#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DigitalClock cl;
    cl.show();
    return a.exec();
}
