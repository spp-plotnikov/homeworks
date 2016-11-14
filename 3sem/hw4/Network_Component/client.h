#pragma once

#include <QObject>

#include "networkentity.h"


/// \brief class for network interactions for   S P P  Simple Scorched Earth game v2.0
/// \author © Sasha Plotnikov Production, Ltd.
class Client : public NetworkEntity
{
    Q_OBJECT
public:
    Client(Game *thisGame);
    ~Client();

private slots:
    void connectToServer();
    void sessionOpened();
};
