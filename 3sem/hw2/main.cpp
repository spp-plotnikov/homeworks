#include "mainwindow.h"
#include "configurationwizard.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ConfigurationWizard cw;

//    cw.sett
    cw.show();

//    MainWindow w;
//    w.show();

    return a.exec();
}
