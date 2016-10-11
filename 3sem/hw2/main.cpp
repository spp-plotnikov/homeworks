#include "configurationwizard.h"
#include "sppsimulatorlantest.h"
#include "sppsimulatorlan.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SPPSimulatorLANTest test;
    QTest::qExec(&test);

    SPPSimulatorLAN simulator;
    ConfigurationWizard cw(simulator);
    cw.show();

    return a.exec();
}
