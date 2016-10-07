#include "configurationwizard.h"
#include "ui_configurationwizard.h"

ConfigurationWizard::ConfigurationWizard(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::ConfigurationWizard)
{
    ui->setupUi(this);

    setPage(1, numberOfComputersPage);
    setPage(2, setOSPage);
}

ConfigurationWizard::~ConfigurationWizard()
{
    delete numberOfComputersPage;
    delete setOSPage;
    delete ui;
}
