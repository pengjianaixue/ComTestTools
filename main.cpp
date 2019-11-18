#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
	QTranslator translator;
	translator.load(".\translations\\qt_en.qm");
	a.installTranslator(&translator);
    a.setStyle("Fusion");
    qRegisterMetaType<size_t>("size_t");
    MainWindow w;
    w.setWindowTitle("Com Assister");
    w.show();
    return a.exec();
}
