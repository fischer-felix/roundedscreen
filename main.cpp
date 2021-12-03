#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow c(nullptr,a.arguments().at(1).toUShort());
    c.show();
    return a.exec();
}
