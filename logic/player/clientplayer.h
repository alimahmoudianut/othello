#ifndef CLIENTPLAYER_H
#define CLIENTPLAYER_H

#include "logic/player.h"
#include <sstream>
using namespace std;

class ClientPlayer : public Player
{
public:
    ClientPlayer(int color, string name);

    void play(Board *board);

    string deepToString(int i = 1) const;

};

#endif // CLIENTPLAYER_H
