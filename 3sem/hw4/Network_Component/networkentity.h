#pragma once

#include <QObject>
#include <QtNetwork>

#include "./Game_Component/game.h"


/// \brief class for network interactions for   S P P  Simple Scorched Earth game v2.0
/// \author © Sasha Plotnikov Production, Ltd.
class NetworkEntity : public QObject
{
    Q_OBJECT

protected slots:
    void acceptMessage();
    void sessionClosed();

private slots:
    void notifyThatCurrentCannonRotatedUp();
    void notifyThatCurrentCannonRotatedDown();
    void notifyThatCurrentCannonMovedRight();
    void notifyThatCurrentCannonMovedLeft();
    void notifyThatCurrentCannonShot();

signals:
    void connectedToOtherNetworkEntity();
    void disconnectedFromOtherNetworkEntity();

    void acceptedThatCurrentCannonRotatedUp();
    void acceptedThatCurrentCannonRotatedDown();
    void acceptedThatCurrentCannonMovedRight();
    void acceptedThatCurrentCannonMovedLeft();
    void acceptedThatCurrentCannonShot();

protected:
    void connectSignalsAndSlotsBetweenGameAndThisObject();

    QTcpSocket *tcpSocket = new QTcpSocket(this);
    Game *game = nullptr;

private:
    enum Events {rotatedUp, rotatedDown, movedRight, movedLeft, shot};

    void sendMessage(NetworkEntity::Events eventOccurred);

    /// \brief to avoid boomerang effect
    /// \details when command comes to this object and forwards to game,
    /// game executes the command and signalize about it,
    /// this signal (that command) is sending back, etc.
    /// This variable allows to avoid this problem
    bool acceptability = true;
};
