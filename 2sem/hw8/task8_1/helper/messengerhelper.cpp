#include <QByteArray>
#include <QDataStream>
#include "messengerhelper.h"

QString MessengerHelper::acceptMessage(QTcpSocket *tcpSocket)
{
    QDataStream in(tcpSocket);
    QString message;
    in >> message;
    return message;
}


void MessengerHelper::sendMessage(QTcpSocket *tcpSocket, const QString &string)
{
    QByteArray outBuffer;
    QDataStream outStream(&outBuffer, QIODevice::WriteOnly);
    outStream << string;
    tcpSocket->write(outBuffer);
}
