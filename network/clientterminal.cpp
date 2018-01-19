#include "network/clientterminal.h"

ClientTerminal::ClientTerminal(QObject *parent) :
    QObject(parent)
{
    myGameStatus = GAME_STATUS_IS_IDLE;
}

void ClientTerminal::doConnect()
{
    mySocket = new QTcpSocket(this);

    connect(mySocket, SIGNAL(connected()),this, SLOT(connected()));
    connect(mySocket, SIGNAL(disconnected()),this, SLOT(disconnected()));
    connect(mySocket, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));
    connect(mySocket, SIGNAL(readyRead()),this, SLOT(readyRead()));

    qDebug() << "connecting...";

    // this is not blocking call
    mySocket->connectToHost("127.0.0.1", 1234);

    // we need to wait...
    if(!mySocket->waitForConnected(5000))
    {
        qDebug() << "Error: " << mySocket->errorString();
    }
}

void ClientTerminal::connected()
{
    qDebug() << "connected...";
    mySocket->write("PLAYER Mehrshad");
}

void ClientTerminal::disconnected()
{
    qDebug() << "disconnected...";
}

void ClientTerminal::bytesWritten(qint64 bytes)
{
    qDebug() << bytes << " bytes written...";
}

void ClientTerminal::readyRead()
{
    qDebug() << "reading...";

    // read the data from the socket
    qDebug() << mySocket->readAll();

    if(myGameStatus == GAME_STATUS_IS_IDLE)
    {
        myGameStatus = GAME_STATUS_IS_PLAYING;
        mySocket->write("NEWGAME");
    }
    else if(myGameStatus == GAME_STATUS_IS_PLAYING)
    {
        myGameStatus = GAME_STATUS_IS_WATCHING;
        mySocket->write("LISTGAME");
    }
}
