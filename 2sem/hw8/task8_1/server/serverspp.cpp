#include <QNetworkConfigurationManager>
#include <QNetworkSession>
#include <QTcpServer>
#include <QTcpSocket>
#include "serverspp.h"
#include "ui_serverspp.h"

ServerSPP::ServerSPP(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerSPP)
{
    ui->setupUi(this);

    setFixedSize(420, 370);
    statusBar()->showMessage("© Sasha Plotnikov Production, Ltd.");
    ui->sendButton->setIcon(QIcon(":new/prefix1/images/send1.png"));

    QNetworkConfigurationManager manager;

    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired)
    {
        networkSession = new QNetworkSession(manager.defaultConfiguration(), this);
        connect(networkSession, SIGNAL(opened()), this, SLOT(sessionOpened()));
        networkSession->open();
    }
    else
    {
        sessionOpened();
    }
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(connectToClient()));
    connect(ui->sendButton, SIGNAL(clicked()), this, SLOT(sendMessage()));
    connect(ui->newMessage, SIGNAL(textChanged()), this, SLOT(sendButtonAbility()));
}

ServerSPP::~ServerSPP()
{
    if (networkSession)
        delete networkSession;

    if (tcpServer)
        delete tcpServer;

    delete tcpSocket;
    delete ui;
}


//------------------------------------------------------------------


void ServerSPP::sessionOpened()
{
    tcpServer = new QTcpServer(this);
    tcpServer->listen();

    QFile port("../port.spp_file");
    port.open(QIODevice::WriteOnly);
    port.write(QString::number(tcpServer->serverPort()).toLocal8Bit().data());
    port.close();
}


void ServerSPP::connectToClient()
{
    tcpSocket = tcpServer->nextPendingConnection();
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(acceptMessage()));
    connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(sessionClosed()));
    ui->sendButton->setEnabled(true);
    ui->chatText->append("Hurray!!! Connected! :-) \n");
}


void ServerSPP::acceptMessage()
{
    QDataStream in(tcpSocket);
    QString message;
    in >> message;
    ui->chatText->append("Client: " + message);
}


void ServerSPP::sessionClosed()
{
    ui->sendButton->setEnabled(false);
    ui->chatText->append("Disconnected :-( \n");
}


void ServerSPP::sendMessage()
{
    QByteArray outBuffer;
    QDataStream outStream(&outBuffer, QIODevice::WriteOnly);
    outStream << ui->newMessage->toPlainText();
    tcpSocket->write(outBuffer);

    ui->chatText->append("Me: " + ui->newMessage->toPlainText());
    ui->newMessage->clear();
}


void ServerSPP::sendButtonAbility()
{
    ui->sendButton->setEnabled(!ui->newMessage->toPlainText().isEmpty());
}
