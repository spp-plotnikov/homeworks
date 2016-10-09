#include "sppsimulatorlan.h"
#include "ui_sppsimulatorlan.h"


SPPSimulatorLAN::SPPSimulatorLAN(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SPPSimulatorLAN)
{
    ui->setupUi(this);
}


void SPPSimulatorLAN::setNetworkAndRun(LocalNetwork *thisNetwork)
{
    if (network != nullptr)
    {
        return;
    }
    network = thisNetwork;
    this->show();
}


SPPSimulatorLAN::~SPPSimulatorLAN()
{
    if (network)
        delete network;
    delete ui;
}
