// network/serverconnection.h

#ifndef SERVERCONNECTION_H
#define SERVERCONNECTION_H

#include <QThread>
#include <QTcpSocket>
#include <string>
#include <QDebug>
#include "logic/game.h"
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

signals:
    void error(QTcpSocket::SocketError socketerror);

public slots:
    void readyRead();
    void disconnected();

private:
    QTcpSocket *mySocket;
    qintptr mySocketDescriptor;
    string myPlayerName;
    int myGameStatus;

    static vector<Game *> ourGames;
};

#endif // SERVERCONNECTION_H
