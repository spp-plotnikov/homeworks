#include <QFile>

#include "client.h"


Client::Client(Game *thisGame)
{
    game = thisGame;
    connect(tcpSocket, SIGNAL(connected()), this, SLOT(sessionOpened()));
    connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(sessionClosed()));
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(acceptMessage()));

    connectSignalsAndSlotsBetweenGameAndThisObject();
}


Client::~Client()
{
    delete tcpSocket;
}


void Client::connectToServer()
{
    QFile port("port.spp_file");
    port.open(QIODevice::ReadWrite | QIODevice::Text);
    QByteArray data = port.readAll();
    port.remove();

    tcpSocket->connectToHost("localhost", data.toInt());
}


void Client::sessionOpened()
{
    emit connectedToOtherNetworkEntity();
}
