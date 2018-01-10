#ifndef GAME_H
#define GAME_H

#include "logic/board.h"
#include "logic/player.h"
#include "logic/player/humanplayer.h"

class Game
{
public:
    Game();

    void start();

private:
    Board *myBoard;
    Player *myFirstPlayer;
    Player *mySecondPlayer;
};

#endif // GAME_H
