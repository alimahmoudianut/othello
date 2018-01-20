#ifndef SERVERPLAYER_H
#define SERVERPLAYER_H

#include "logic/player.h"

class ServerPlayer : public Player
{
public:
    ServerPlayer(int color, string name);

    void play(Board *board);

    string deepToString(int i = 1) const;
};

#endif // SERVERPLAYER_H
