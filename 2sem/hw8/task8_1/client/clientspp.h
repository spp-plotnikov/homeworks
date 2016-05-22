#pragma once

#include <QMainWindow>
#include <QtNetwork>

namespace Ui {
class ClientSPP;
}

class ClientSPP : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClientSPP(QWidget *parent = 0);
    ~ClientSPP();

private slots:
    void connectToServer();
    void acceptMessage();
    void sendMessage();
    void sessionOpened();
    void sessionClosed();

private:
    Ui::ClientSPP *ui;

    QTcpSocket *tcpSocket = new QTcpSocket(this);
};
