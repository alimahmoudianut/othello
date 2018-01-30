#ifndef CLIENT_TERMINAL_H
#define CLIENT_TERMINAL_H

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include <string>
using namespace std;

#define GAME_STATUS_IS_PLAYING 0
#define GAME_STATUS_IS_IDLE 1
#define GAME_STATUS_IS_WATCHING 2


class ClientTerminal : public QObject
{
    Q_OBJECT
public:
    explicit ClientTerminal(QObject *parent = 0);

    void doConnect();
    void request(string request);

    string getLastResponse() const;
signals:

public slots:
    void connected();
    void disconnected();
    void readyRead();

private:
    QTcpSocket *mySocket;
    int myGameStatus;
    string myLastResponse;
};

#endif // CLIENT_TERMINAL_H
