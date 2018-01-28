// network/serverconnection.h

#ifndef SERVERCONNECTION_H
#define SERVERCONNECTION_H

#include <QThread>
#include <QTcpSocket>
#include <string>
#include <QDebug>
#include "logic/game.h"
#include "logic/player/clientplayer.h"
#include "network/servercli.h"
#include <vector>
using namespace std;

#define STATUS_IS_PLAYING 0
#define STATUS_IS_WATCHING 1
#define STATUS_IS_IDLE 2


class ServerConnection : public QThread
{
    Q_OBJECT
public:
    explicit ServerConnection(qintptr ID, QObject *parent = 0);

    void run();

    string toString() const;

    static vector<Game *> ourGames;
    Game *findMyGame() const;
    int removeMyGame() const;

signals:
    void error(QTcpSocket::SocketError socketerror);

public slots:
    void readyRead();
    void disconnected();

private:
    int importIntoGame(int gameID);

    QTcpSocket    * mySocket;
    qintptr         mySocketDescriptor;
    Player        * myPlayer;
    int             myGameStatus;

};

#endif // SERVERCONNECTION_H
