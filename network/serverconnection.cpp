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
    myPlayer = NULL;
}

void ServerConnection::run()
{
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
    cout << "Client " << mySocketDescriptor << " connected" << endl;

    exec();
}

string ServerConnection::toString() const
{
    stringstream out;
    out << "Server Connection #" << mySocketDescriptor << endl;
    out << myPlayer->toString() << endl;
    return out.str();
}

void ServerConnection::readyRead()
{
    // get the information
    QByteArray data = mySocket->readAll();

    // will write on server side window
    cout << endl << "Client " << mySocketDescriptor << " >>  " << data.toStdString() << endl;

    stringstream ss(data.toStdString());
    string cmd;
    ss >> cmd;

    if(cmd == "PLAYER")
    {
        string playerName;
        ss >> playerName;
        myPlayer = new ClientPlayer(WHITE, playerName, mySocket);
        cout << myPlayer->deepToString(1, 2) << endl;
        cout << COMMAND_PROMPT ;
        cout.flush();
        mySocket->write(myPlayer->toString().c_str());
    }
    else if(cmd == "NEWGAME")
    {
        if((this->myGameStatus == STATUS_IS_IDLE) && (myPlayer != NULL))
        {
            Game *g = new Game(TERMINAL_SERVER);
            g->setFirstPlayer(myPlayer);
            cout << g->deepToString() << endl;
            cout << COMMAND_PROMPT;
            cout.flush();
            ourGames.push_back(g);
            mySocket->write(g->toString().c_str());
        }
    }
    else if(cmd == "LISTGAME")
    {
        for(unsigned int i = 0; i < ourGames.size(); i++)
        {
            mySocket->write(ourGames[i]->toString().c_str());
        }
    }
    else if(cmd == "JOIN")
    {
        int gameID;
        ss >> gameID;
        if(importIntoGame(gameID) == 0)
           mySocket->write("GAMEJOINED");
        else
            mySocket->write("FAILED TO JOIN");
    }

}

void ServerConnection::disconnected()
{
    cout << mySocketDescriptor << " Disconnected";


    mySocket->deleteLater();
    exit(0);
}

int ServerConnection::importIntoGame(int gameID)
{
    for(unsigned int i = 0; i < ourGames.size(); i++)
    {
        if(ourGames[i]->getID() == gameID && ourGames[i]->getFirstPlayer() != myPlayer)
        {
            ourGames[i]->setSecondPlayer(myPlayer);
            myPlayer->setColor(BLACK);
            ourGames[i]->start(1);
            return 0;
        }
    }
    return -1;
}
