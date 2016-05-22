#include <QNetworkConfigurationManager>
#include <QNetworkSession>
#include <QTcpServer>
#include <QTcpSocket>
#include "serverspp.h"
#include "ui_serverspp.h"

ServerSPP::ServerSPP(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerSPP)
{
    ui->setupUi(this);

    setFixedSize(420, 370);
    statusBar()->showMessage("© Sasha Plotnikov Production, Ltd.");
    ui->sendButton->setIcon(QIcon(":new/prefix1/images/send1.png"));

    QNetworkConfigurationManager manager;

    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired)
    {
        networkSession = new QNetworkSession(manager.defaultConfiguration(), this);
        connect(networkSession, SIGNAL(opened()), this, SLOT(sessionOpened()));
        networkSession->open();
    }
    else
    {
        sessionOpened();
    }

}

ServerSPP::~ServerSPP()
{
    if (networkSession)
        delete networkSession;

    if (tcpServer)
        delete tcpServer;

    delete tcpSocket;
    delete ui;
}


//------------------------------------------------------------------


void ServerSPP::sessionOpened()
{
    tcpServer = new QTcpServer(this);
    tcpServer->listen();

    QFile port("../port.spp_file");
    port.open(QIODevice::WriteOnly);
    port.write(QString::number(tcpServer->serverPort()).toLocal8Bit().data());
    port.close();
}
