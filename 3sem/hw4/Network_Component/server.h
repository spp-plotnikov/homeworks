#pragma once

#include <QObject>
#include <QtNetwork>

#include "networkentity.h"


class Server : public NetworkEntity
{
    Q_OBJECT
public:
    Server(Game *thisGame);
    ~Server();

private slots:
    void connectToClient();
    void sessionOpened();

private:
    QTcpServer *tcpServer = nullptr;
    QNetworkSession *networkSession = nullptr;
};
