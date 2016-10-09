#include "configurationwizard.h"
#include "sppsimulatorlan.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SPPSimulatorLAN simulator;
    ConfigurationWizard cw(simulator);
    cw.show();

    return a.exec();
}
