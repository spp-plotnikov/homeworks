#include <QFile>
#include <QString>
#include <QByteArray>
#include "clientspp.h"
#include "ui_clientspp.h"

ClientSPP::ClientSPP(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientSPP)
{
    ui->setupUi(this);

    setFixedSize(420, 370);
    ui->sendButton->setIcon(QIcon(":new/prefix1/images/send1.png"));
    ui->tryToConnectButton->setIcon(QIcon(":new/prefix1/images/connect4.png"));
    statusBar()->showMessage("© Sasha Plotnikov Production, Ltd.");

    connect(ui->tryToConnectButton, SIGNAL(clicked()), this, SLOT(connectToServer()));
}

ClientSPP::~ClientSPP()
{
    delete tcpSocket;
    delete ui;
}


//------------------------------------------------------------------


void ClientSPP::connectToServer()
{
    QFile port("../port.spp_file");
    port.open(QIODevice::ReadWrite | QIODevice::Text);
    QByteArray data = port.readAll();
    port.remove();

    tcpSocket->abort();
    tcpSocket->connectToHost("localhost", data.toInt());
}
