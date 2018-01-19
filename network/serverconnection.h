// network/serverconnection.h

#ifndef SERVERCONNECTION_H
#define SERVERCONNECTION_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>

class ServerConnection : public QThread
{
    Q_OBJECT
public:
    explicit ServerConnection(qintptr ID, QObject *parent = 0);

    void run();

signals:
    void error(QTcpSocket::SocketError socketerror);

public slots:
    void readyRead();
    void disconnected();

private:
    QTcpSocket *socket;
    qintptr socketDescriptor;
};

#endif // SERVERCONNECTION_H
