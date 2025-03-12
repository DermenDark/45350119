#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Лифт в доме");
    w.setFixedSize(450, 640);
    w.show();
    return a.exec();
}
