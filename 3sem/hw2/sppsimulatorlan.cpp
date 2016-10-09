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
    fillTable();
    this->show();
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
        enum {Windows, Linux, MacOS};
        switch (network->getOSByIndex(i - 1))
        {
        case Windows:
        {
            item->setIcon(QIcon(":/new/prefix1/images/windows.png"));
            break;
        }
        case Linux:
        {
            item->setIcon(QIcon(":/new/prefix1/images/linux.png"));
            break;
        }
        case MacOS:
        {
            item->setIcon(QIcon(":/new/prefix1/images/macos.png"));
            break;
        }
        }
        ui->tableWidget->setItem(i, 1, item);
        ui->tableWidget->setIconSize(QSize(23, 23));
    }
}


SPPSimulatorLAN::~SPPSimulatorLAN()
{
    if (network)
        delete network;
    ui->tableWidget->clear();
    delete ui;
}
