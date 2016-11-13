#include "networkentity.h"


void NetworkEntity::acceptMessage()
{
//    QString message = MessengerHelper::acceptMessage(tcpSocket);
}


void NetworkEntity::sendMessage()
{
//    MessengerHelper::sendMessage(tcpSocket, ui->newMessage->toPlainText());
}


void NetworkEntity::sessionClosed()
{
    emit disconnectedFromOtherNetworkEntity();
}
