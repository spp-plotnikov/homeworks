#include <QNetworkConfigurationManager>
#include <QNetworkSession>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>

#include "server.h"

Server::Server()
{
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
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(connectToClient()));
}


Server::~Server()
{
    if (networkSession)
    {
        delete networkSession;
    }
    if (tcpServer)
    {
        delete tcpServer;
    }
}


void Server::sessionOpened()
{
    tcpServer = new QTcpServer(this);
    tcpServer->listen();

    QFile port("port.spp_file");
    port.open(QIODevice::WriteOnly);
    port.write(QString::number(tcpServer->serverPort()).toLocal8Bit().data());
    port.close();
}


void Server::connectToClient()
{
    tcpSocket = tcpServer->nextPendingConnection();
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(acceptMessage()));
    connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(sessionClosed()));
    emit connectedToOtherNetworkEntity();
}
