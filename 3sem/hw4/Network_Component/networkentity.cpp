#include <QByteArray>
#include <QDataStream>

#include "networkentity.h"


void NetworkEntity::acceptMessage()
{
    QDataStream in(tcpSocket);
    int senderEvent;
    in >> senderEvent;

    switch (senderEvent)
    {
    case rotatedDown:
    {
        emit acceptedThatCurrentCannonRotatedDown();
        break;
    }
    case rotatedUp:
    {
        emit acceptedThatCurrentCannonRotatedUp();
        break;
    }
    case movedLeft:
    {
        emit acceptedThatCurrentCannonMovedLeft();
        break;
    }
    case movedRight:
    {
        emit acceptedThatCurrentCannonMovedRight();
        break;
    }
    case shot:
    {
        emit acceptedThatCurrentCannonShot();
        break;
    }
    }

    acceptability = false;
}


void NetworkEntity::sendMessage(Events eventOccurred)
{
    if (!acceptability)
    {
        acceptability = true;
        return;
    }

    QByteArray outBuffer;
    QDataStream outStream(&outBuffer, QIODevice::WriteOnly);
    outStream << eventOccurred;
    tcpSocket->write(outBuffer);
}


void NetworkEntity::sessionClosed()
{
    emit disconnectedFromOtherNetworkEntity();
}


void NetworkEntity::connectSignalsAndSlotsBetweenGameAndThisObject()
{
    connect(game, SIGNAL(currentCannonMovedLeft()), this, SLOT(notifyThatCurrentCannonMovedLeft()));
    connect(game, SIGNAL(currentCannonMovedRight()), this, SLOT(notifyThatCurrentCannonMovedRight()));
    connect(game, SIGNAL(currentCannonRotatedDown()), this, SLOT(notifyThatCurrentCannonRotatedDown()));
    connect(game, SIGNAL(currentCannonRotatedUp()), this, SLOT(notifyThatCurrentCannonRotatedUp()));
    connect(game, SIGNAL(currentCannonShot()), this, SLOT(notifyThatCurrentCannonShot()));

    connect(this, SIGNAL(acceptedThatCurrentCannonMovedLeft()), game, SLOT(moveCurrentCannonLeft()));
    connect(this, SIGNAL(acceptedThatCurrentCannonMovedRight()), game, SLOT(moveCurrentCannonRight()));
    connect(this, SIGNAL(acceptedThatCurrentCannonRotatedDown()), game, SLOT(rotateCurrentCannonDown()));
    connect(this, SIGNAL(acceptedThatCurrentCannonRotatedUp()), game, SLOT(rotateCurrentCannonUp()));
    connect(this, SIGNAL(acceptedThatCurrentCannonShot()), game, SLOT(shotCurrentCannon()));
}


void NetworkEntity::notifyThatCurrentCannonMovedLeft()
{
    sendMessage(movedLeft);
}


void NetworkEntity::notifyThatCurrentCannonMovedRight()
{
    sendMessage(movedRight);
}


void NetworkEntity::notifyThatCurrentCannonRotatedDown()
{
    sendMessage(rotatedDown);
}


void NetworkEntity::notifyThatCurrentCannonRotatedUp()
{
    sendMessage(rotatedUp);
}


void NetworkEntity::notifyThatCurrentCannonShot()
{
    sendMessage(shot);
}
