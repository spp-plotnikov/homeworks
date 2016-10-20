#include "sppsimulatorlan.h"
#include "ui_sppsimulatorlan.h"
#include "Logic_component/sppsimulatorlanhelper.h"
#include "Logic_component/operatingsystemsenumeration.h"


SPPSimulatorLAN::SPPSimulatorLAN(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SPPSimulatorLAN)
{
    ui->setupUi(this);
    statusBar()->showMessage("© Sasha Plotnikov Production, Ltd.");
    statusBar()->setEnabled(false);
    setWindowIcon(QIcon(":/new/prefix1/logoSPP.ico"));
    setWindowTitle("S P P  Simulator of LAN");
    ui->pushButton->setIcon(QIcon(":/new/prefix1/nextMove.png"));
    ui->pushButton_2->setIcon(QIcon(":/new/prefix1/exit1.png"));

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(makeMove()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(close()));
}


void SPPSimulatorLAN::setNetwork(LocalNetwork *thisNetwork)
{
    if (network != nullptr)
    {
        return;
    }

    network = thisNetwork;
    fillTable();
}


void SPPSimulatorLAN::fillTable()
{
    const int columnCount = 4;  //  for OS, number, infection status and connections
    ui->tableWidget->setColumnCount(columnCount);
    ui->tableWidget->setRowCount(network->getNetworkSize() + 1);
    ui->tableWidget->setCellWidget(0, 0, new QLabel("ID"));
    ui->tableWidget->setCellWidget(0, 1, new QLabel("OS"));
    ui->tableWidget->setCellWidget(0, 2, new QLabel("Virus"));
    ui->tableWidget->setCellWidget(0, 3, new QLabel("Connected computers"));

    QString temp;
    for (int i = 1; i <= network->getNetworkSize(); i++)
    {
        temp.setNum(i);
        temp = QString("№") + temp;
        ui->tableWidget->setCellWidget(i, 0, new QLabel(temp));

        QTableWidgetItem *item = new QTableWidgetItem();
        switch (network->getOSByIndex(i - 1))
        {
        case OS::Windows:
        {
            item->setIcon(QIcon(":/new/prefix1/windows.png"));
            break;
        }
        case OS::Linux:
        {
            item->setIcon(QIcon(":/new/prefix1/linux.png"));
            break;
        }
        case OS::MacOS:
        {
            item->setIcon(QIcon(":/new/prefix1/macos.png"));
            break;
        }
        }
        ui->tableWidget->setItem(i, 1, item);
        ui->tableWidget->setIconSize(QSize(23, 23));

        QString connections;
        QString temp;
        QList<int> connectedComputers(network->getConnectionsByIndex(i - 1));
        for (int j = 0; j < connectedComputers.size(); j++)
        {
            temp.setNum(connectedComputers[j] + 1);
            if (j != 0)
            {
                connections = connections + ", ";
            }
            connections = connections + temp;
        }
        ui->tableWidget->setCellWidget(i, 3, new QLabel(connections));

        ui->tableWidget->setItem(i, 2, new QTableWidgetItem());
    }
    updateTable();
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}


void SPPSimulatorLAN::updateTable()
{
    for (int i = 0; i < network->getNetworkSize(); i++)
    {
        if (network->getStatusOfInfestationByIndex(i))
        {
            ui->tableWidget->item(i + 1, 2)->setIcon(QIcon(":/new/prefix1/virus.png"));
        }
    }
    ui->tableWidget->resizeColumnsToContents();
}


void SPPSimulatorLAN::makeMove()
{
    SPPSimulatorLANHelper::nextStep(network);
    updateTable();
}


SPPSimulatorLAN::~SPPSimulatorLAN()
{
    if (network)
        delete network;
    ui->tableWidget->clear();
    delete ui;
}
