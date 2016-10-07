#include "configurationwizard.h"
#include "ui_configurationwizard.h"

ConfigurationWizard::ConfigurationWizard(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::ConfigurationWizard)
{
    ui->setupUi(this);

    setPage(1, numberOfComputersPage);
}

ConfigurationWizard::~ConfigurationWizard()
{
    delete numberOfComputersPage;
    delete ui;
}
