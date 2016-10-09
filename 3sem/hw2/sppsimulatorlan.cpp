#include "sppsimulatorlan.h"
#include "ui_sppsimulatorlan.h"


SPPSimulatorLAN::SPPSimulatorLAN(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SPPSimulatorLAN)
{
    ui->setupUi(this);
    statusBar()->showMessage("© Sasha Plotnikov Production, Ltd.");
    statusBar()->setEnabled(false);
    setWindowIcon(QIcon(":/new/prefix1/images/logoSPP.ico"));
    setWindowTitle("S P P  Simulator of LAN");
    ui->pushButton->setIcon(QIcon(":/new/prefix1/images/nextMove.png"));
    ui->pushButton_2->setIcon(QIcon(":/new/prefix1/images/exit1.png"));

    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(close()));
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
