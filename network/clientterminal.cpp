#include "network/clientterminal.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

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

    cout << "connecting..." << endl;

    // this is not blocking call
    mySocket->connectToHost("127.0.0.1", 1234);

    // we need to wait...
    if(!mySocket->waitForConnected(5000))
    {
        cout << "Error: " << mySocket->errorString().toStdString() << endl;
    }
}

void ClientTerminal::request(string request)
{
    string cmd;
    stringstream ss(request);
    ss >> cmd;


    if(cmd == "NEWGAME")
    {
        if(myGameStatus == GAME_STATUS_IS_IDLE)
        {
            myGameStatus = GAME_STATUS_IS_PLAYING;
            mySocket->write("NEWGAME");
        }
    }
    else if(cmd == "LISTGAME")
    {
        mySocket->write("LISTGAME");
    }
    else if(cmd == "JOIN")
    {
        int gameID;
        char msg[32];
        ss >> gameID;
        sprintf(msg, "JOIN %d", gameID);
        mySocket->write(msg);
    }
    else if(cmd == "WATCH")
    {
        mySocket->write("WATCH");
    }
    else if(cmd == "START")
    {
        mySocket->write("START");
    }
    else if(cmd == "STATUS")
    {
        mySocket->write("STATUS");
    }
    else if(cmd == "LASTMV")
    {
        mySocket->write("LASTMV");
    }
    else if(cmd == "ENDGAME")
    {
        mySocket->write("ENDGAME");
    }
    else if(cmd == "MV")
    {
        string mv;
        char msg[32];
        ss >> mv;
        sprintf(msg, "MV %s", mv.c_str());
        mySocket->write(msg);
    }

}

string ClientTerminal::getLastResponse() const
{
    return myLastResponse;
}

void ClientTerminal::connected()
{
    cout << "connected..." << endl;
    mySocket->write("PLAYER Mehrshad");
}

void ClientTerminal::disconnected()
{
    cout << "disconnected..." << endl;
}

void ClientTerminal::readyRead()
{
    cout << "reading..." << endl;

    // read the data from the socket
    myLastResponse = mySocket->readAll().toStdString();
    cout << myLastResponse << endl;
}
