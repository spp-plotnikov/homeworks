#include "GUI_component/configurationwizard.h"
#include "Logic_component/sppsimulatorlanhelpertest.h"
#include "GUI_component/sppsimulatorlan.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SPPSimulatorLANHelperTest test;
    QTest::qExec(&test);

    SPPSimulatorLAN simulator;
    ConfigurationWizard cw(simulator);
    cw.show();

    return a.exec();
}
