#include "mainwindow.h"
#include "configurationwizard.h"
#include "intropage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ConfigurationWizard cw;

    IntroPage page1;
    cw.addPage(&page1);

    cw.show();

    MainWindow w;
    w.show();

    return a.exec();
}
