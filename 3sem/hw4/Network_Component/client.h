#pragma once

#include <QObject>

#include "networkentity.h"


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
