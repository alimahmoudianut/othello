#ifndef CLIENTPLAYER_H
#define CLIENTPLAYER_H

#include "logic/player.h"
#include <QTcpSocket>
#include <sstream>
using namespace std;

class ClientPlayer : public Player
{
public:
    ClientPlayer(int color, string name, QTcpSocket * socket);

    string play(Board const * const board);
    string deepToString(int i = 1) const;

private:
    QTcpSocket * mySocket;

};

#endif // CLIENTPLAYER_H
