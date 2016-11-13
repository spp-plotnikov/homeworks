#pragma once

#include <QObject>
#include <QtNetwork>

#include "./Game_Component/game.h"


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
    /// \todo  more detailed comment for this variable
    bool acceptability = true;
};
