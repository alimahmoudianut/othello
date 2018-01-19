// network/serverterminal.h

#ifndef SERVERTERMINAL_H
#define SERVERTERMINAL_H

#include <QTcpServer>
#include "network/serverconnection.h"


class ServerTerminal : public QTcpServer
{
    Q_OBJECT
public:
    explicit ServerTerminal(QObject *parent = 0);
    void startServer();
signals:

public slots:

protected:
    void incomingConnection(qintptr socketDescriptor);


};

#endif // SERVERTERMINAL_H
