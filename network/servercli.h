#ifndef SERVERCLI_H
#define SERVERCLI_H

#include <QThread>

class ServerCLI : public QThread
{
public:
    ServerCLI();

    void run();

private:

};

#endif // SERVERCLI_H
