#pragma once

#include <QMainWindow>
#include <QtNetwork>
#include <QtWidgets>
#include <QWidget>


namespace Ui {
class ServerSPP;
}

class ServerSPP : public QMainWindow
{
    Q_OBJECT

public:
    explicit ServerSPP(QWidget *parent = 0);
    ~ServerSPP();

private slots:
//    void connectToClient();
//    void acceptMessage();
//    void sendMessage();
    void sessionOpened();
//    void sessionClosed();
//    /// \brief this slot makes button disabled if newMessage is empty
//    void sendButtonAbility();

private:
    Ui::ServerSPP *ui;
    QTcpSocket *tcpSocket = new QTcpSocket(this);
    QTcpServer *tcpServer = nullptr;
    QNetworkSession *networkSession = nullptr;
};
