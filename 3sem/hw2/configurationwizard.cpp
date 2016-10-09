#include "configurationwizard.h"
#include "ui_configurationwizard.h"


ConfigurationWizard::ConfigurationWizard(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::ConfigurationWizard)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/new/prefix1/logoSPP.ico"));

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

}


ConfigurationWizard::~ConfigurationWizard()
{
    delete numberOfComputersPage;
    delete setOSPage;
    delete tablePage;
    delete ui;
}
