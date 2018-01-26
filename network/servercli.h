#ifndef SERVERCLI_H
#define SERVERCLI_H

#include <QThread>

#define COMMAND_PROMPT  "Command (m for help) >> "

class ServerCLI : public QThread
{
public:
    ServerCLI();

    void run();

private:

};

#endif // SERVERCLI_H
