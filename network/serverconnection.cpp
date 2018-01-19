// network/serverconnection.cpp

#include "network/serverconnection.h"
#include <iostream>
#include <sstream>
using namespace std;

vector<Game *> ServerConnection::ourGames;

ServerConnection::ServerConnection(qintptr ID, QObject *parent) :
    QThread(parent)
{
    this->mySocketDescriptor = ID;
    this->myGameStatus = STATUS_IS_IDLE;
}

void ServerConnection::run()
{
    // thread starts here
    cout << " Thread started" << endl;

    mySocket = new QTcpSocket();

    // set the ID
    if(!mySocket->setSocketDescriptor(this->mySocketDescriptor))
    {
        // something's wrong, we just emit a signal
        emit error(mySocket->error());
        return;
    }

    // connect socket and signal
    // note - Qt::DirectConnection is used because it's multithreaded
    //        This makes the slot to be invoked immediately, when the signal is emitted.

    connect(mySocket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(mySocket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    // We'll have multiple clients, we want to know which is which
    cout << mySocketDescriptor << " Client connected" << endl;

    // make this thread a loop,
    // thread will stay alive so that signal/slot to function properly
    // not dropped out in the middle when thread dies

    exec();
}

string ServerConnection::toString() const
{
    stringstream out;
    out << "Server Connection #" << mySocketDescriptor << endl;
    out << "player name : " << myPlayerName << endl;
    return out.str();
}

void ServerConnection::readyRead()
{
    // get the information
    QByteArray data = mySocket->readAll();

    // will write on server side window
    cout << mySocketDescriptor << " Data in: " << data.toStdString() << endl;

    mySocket->write(data);

    stringstream ss(data.toStdString());
    string cmd;
    ss >> cmd;

    if(cmd == "PLAYER")
    {
        string playerName;
        ss >> playerName;
        myPlayerName = playerName;
        cout << this->toString() << endl;
    }
    else if(cmd == "NEWGAME")
    {
        if(this->myGameStatus == STATUS_IS_IDLE)
        {
            Game *g = new Game();
            ourGames.push_back(g);
        }
    }
    else if(cmd == "LISTGAME")
    {
        for(unsigned int i = 0; i < ourGames.size(); i++)
        {
            cout << ourGames[i]->toDeepString() << endl;
        }
    }
}

void ServerConnection::disconnected()
{
    cout << mySocketDescriptor << " Disconnected";


    mySocket->deleteLater();
    exit(0);
}
