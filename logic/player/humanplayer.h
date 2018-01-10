#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "logic/player.h"

class HumanPlayer : public Player
{
public:
    HumanPlayer(int color);

    void play(Board *board);
};

#endif // HUMANPLAYER_H
