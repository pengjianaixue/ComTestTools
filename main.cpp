#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    a.setStyle("Fusion");
    qRegisterMetaType<size_t>("size_t");
    MainWindow w;
    w.setWindowTitle("Com Assister");
    w.show();
    return a.exec();
}
