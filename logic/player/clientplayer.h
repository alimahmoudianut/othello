#ifndef CLIENTPLAYER_H
#define CLIENTPLAYER_H

#include "logic/player.h"

class ClientPlayer : public Player
{
public:
    ClientPlayer(int color, string name);

    void play(Board *board);

};

#endif // CLIENTPLAYER_H
