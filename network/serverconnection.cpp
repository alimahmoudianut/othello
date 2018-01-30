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

Game *ServerConnection::findMyGame() const
{
    for(unsigned int i = 0; i < ourGames.size(); i++)
    {
        if(ourGames[i]->getFirstPlayer() == myPlayer || ourGames[i]->getSecondPlayer() == myPlayer)
        {
            return ourGames[i];
        }
    }
    return NULL;
}

int ServerConnection::removeMyGame() const
{
    for(unsigned int i = 0; i < ourGames.size(); i++)
    {
        if(ourGames[i]->getFirstPlayer() == myPlayer || ourGames[i]->getSecondPlayer() == myPlayer)
        {
            Game *g = ourGames[i];
            ourGames.erase(ourGames.begin() + i);
            delete g;
            return 0;
        }
    }
    return -1;
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
            g->setGameType(2);
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
    else if(cmd == "MV")
    {
        string mv;
        ss >> mv;
        int ret = findMyGame()->addMovement(mv, myPlayer);
        if(ret == 0)
        {
            mySocket->write("MVADDED");
        }
        else if(ret == -1)
        {
            mySocket->write("INVALIDMV");
        }
        else if(ret == -2)
        {
            mySocket->write("NOT YOUR TURN");
        }
        else if(ret == -3)
        {
            mySocket->write("GAME NOT STARTED");
        }
    }
    else if(cmd == "STATUS")
    {
        Game *g = findMyGame();
        if(g == NULL)
        {
            mySocket->write("NO GAME FOUND");
        }
        else if(g->getNumberOfPlayers() == 1)
        {
            mySocket->write("WAIT FOR OPPONENT JOIN");
        }
        else if(g->isPlayerTurn(myPlayer) == 0)
        {
            mySocket->write("YOUR TURN");
        }
        else
        {
            mySocket->write("WAIT FOR OPPONENT TURN");
        }
    }
    else if(cmd == "ENDGAME")
    {
        if(removeMyGame() == 0)
            mySocket->write("GAMEFINISHED");
        else
            mySocket->write("NO GAME FOUND");
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
            if(ourGames[i]->getSecondPlayer() == NULL)
            {
                ourGames[i]->setSecondPlayer(myPlayer);
                myPlayer->setColor(BLACK);
                return 0;
            }
            else
                return -2;
        }
    }
    return -1;
}
