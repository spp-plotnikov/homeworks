#pragma once

#include <QString>
#include <QTcpSocket>

/*!
 * \brief This is a helper class for tcp-messengers.
 * It provides the capability to receive and send messages.
 */
class MessengerHelper
{
public:
    /// \brief gets string from socket
    static QString acceptMessage(QTcpSocket *tcpSocket);
    /// \brief puts string to socket
    static void sendMessage(QTcpSocket *tcpSocket, const QString &string);
};
