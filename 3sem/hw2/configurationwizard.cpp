#include "configurationwizard.h"
#include "ui_configurationwizard.h"

ConfigurationWizard::ConfigurationWizard(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::ConfigurationWizard)
{
    ui->setupUi(this);

    setPage(1, numberOfComputersPage);
    setPage(2, setOSPage);

    connect(this, SIGNAL(currentIdChanged(int)),
            this, SLOT(changeCurrentForm()));
}


void ConfigurationWizard::changeCurrentForm()
{
    if (currentId() == 2)
    {
        setOSPage->changeNumberOfComputers(numberOfComputersPage->getNumberOfComputrs());
    }
}


ConfigurationWizard::~ConfigurationWizard()
{
    delete numberOfComputersPage;
    delete setOSPage;
    delete ui;
}
