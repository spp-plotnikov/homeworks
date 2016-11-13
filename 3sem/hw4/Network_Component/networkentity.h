#pragma once

#include <QObject>
#include <QtNetwork>


class NetworkEntity : public QObject
{
    Q_OBJECT

protected slots:
    void acceptMessage();
    void sendMessage();
    void sessionClosed();

signals:
    void connectedToOtherNetworkEntity();
    void disconnectedFromOtherNetworkEntity();

protected:
     QTcpSocket *tcpSocket = new QTcpSocket(this);
};
