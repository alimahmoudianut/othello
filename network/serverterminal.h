// network/serverterminal.h

#ifndef SERVERTERMINAL_H
#define SERVERTERMINAL_H

#include <QTcpServer>
#include "network/serverconnection.h"
#include "network/servercli.h"
#include <vector>
using namespace std;


class ServerTerminal : public QTcpServer
{
    Q_OBJECT
public:
    explicit ServerTerminal(QObject *parent = 0);
    void startServer();
    void startCLI();
signals:

public slots:

protected:
    void incomingConnection(qintptr socketDescriptor);

private:
    vector <ServerConnection *> myThreads;
    ServerCLI *myServerCLI;
};

#endif // SERVERTERMINAL_H
