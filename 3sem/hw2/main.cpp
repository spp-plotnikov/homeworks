#include "GUI_component/configurationwizard.h"
#include "Logic_component/sppsimulatorlantest.h"
#include "GUI_component/sppsimulatorlan.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    SPPSimulatorLANTest test;
//    QTest::qExec(&test);

    SPPSimulatorLAN simulator;
    ConfigurationWizard cw(simulator);
    cw.show();

    return a.exec();
}
