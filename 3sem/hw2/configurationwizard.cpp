#include "configurationwizard.h"
#include "ui_configurationwizard.h"

ConfigurationWizard::ConfigurationWizard(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::ConfigurationWizard)
{
    ui->setupUi(this);

    setPage(1, numberOfComputersPage);
    setPage(2, setOSPage);
    setPage(3, tablePage);

    connect(this, SIGNAL(currentIdChanged(int)),
            this, SLOT(changeCurrentForm()));
}


void ConfigurationWizard::changeCurrentForm()
{
    const int numberOfComputers = numberOfComputersPage->getNumberOfComputers();
    setOSPage->changeNumberOfComputers(numberOfComputers);
    tablePage->generateTable(numberOfComputers);
}


ConfigurationWizard::~ConfigurationWizard()
{
    delete numberOfComputersPage;
    delete setOSPage;
    delete tablePage;
    delete ui;
}
