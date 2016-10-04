#include "configurationwizard.h"
#include "ui_configurationwizard.h"

ConfigurationWizard::ConfigurationWizard(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::ConfigurationWizard)
{
    ui->setupUi(this);    
}

ConfigurationWizard::~ConfigurationWizard()
{
    delete ui;
}
