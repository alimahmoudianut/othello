// network/serverterminal.cpp

#include "network/serverterminal.h"
#include "network/serverconnection.h"
#include <iostream>
using namespace std;

ServerTerminal::ServerTerminal(QObject *parent) :
    QTcpServer(parent)
{
    myServerCLI = new ServerCLI();
}

void ServerTerminal::startServer()
{
    int port = 1234;

    if(!this->listen(QHostAddress::Any,port))
    {
        qDebug() << "Could not start server";
    }
    else
    {
        qDebug() << "Listening to port " << port << "...";
    }
}

void ServerTerminal::startCLI()
{
    myServerCLI->start();
}

void ServerTerminal::incomingConnection(qintptr socketDescriptor)
{
    // We have a new connection
    qDebug() << socketDescriptor << " Connecting...";

    ServerConnection *thread = new ServerConnection(socketDescriptor, this);
    myThreads.push_back(thread);

    // connect signal/slot
    // once a thread is not needed, it will be beleted later
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    thread->start();
}
