#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "logic/player.h"

class HumanPlayer : public Player
{
public:
    HumanPlayer(int color, string name);

    string play(const Board * const board);
};

#endif // HUMANPLAYER_H
