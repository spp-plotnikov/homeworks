#include "configurationwizard.h"
#include "ui_configurationwizard.h"


ConfigurationWizard::ConfigurationWizard(SPPSimulatorLAN &owner, QWidget *parent) :
    simulator(owner),
    QWizard(parent),
    ui(new Ui::ConfigurationWizard)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/new/prefix1/images/logoSPP.ico"));

    setPage(1, numberOfComputersPage);
    setPage(2, setOSPage);
    setPage(3, tablePage);

    connect(this, SIGNAL(currentIdChanged(int)),
            this, SLOT(changeCurrentForm()));
    connect(this, SIGNAL(finished(int)),
            this, SLOT(runSPPSimulatorLAN()));
}


void ConfigurationWizard::changeCurrentForm()
{
    const int numberOfComputers = numberOfComputersPage->getNumberOfComputers();
    if (previousId == 1)
    {
        setOSPage->changeNumberOfComputers(numberOfComputers);
        tablePage->generateTable(numberOfComputers);
    }
    previousId = currentId();
}


void ConfigurationWizard::runSPPSimulatorLAN()
{
    LocalNetwork *network = new LocalNetwork(numberOfComputersPage->getNumberOfComputers(),
                                             setOSPage->getListOfOperatingSystems(),
                                             tablePage->getAdjacencyMatrix());
    simulator.setNetwork(network);
    simulator.show();
}


ConfigurationWizard::~ConfigurationWizard()
{
    delete numberOfComputersPage;
    delete setOSPage;
    delete tablePage;
    delete ui;
}
