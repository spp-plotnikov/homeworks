#pragma once

#include <QObject>
#include <QtNetwork>

#include "networkentity.h"


/// \brief class for network interactions for   S P P  Simple Scorched Earth game v2.0
/// \author © Sasha Plotnikov Production, Ltd.
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
