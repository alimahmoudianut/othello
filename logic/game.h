#ifndef GAME_H
#define GAME_H

#include "logic/board.h"
#include "logic/player.h"
#include "logic/player/humanplayer.h"

#define TERMINAL_SERVER 0
#define TERMINAL_CLIENT 1
#define TERMINAL_OFFLINE 2

class Game
{
public:
    Game(int type = TERMINAL_OFFLINE);

    void start();

private:
    Board *myBoard;
    Player *myFirstPlayer;
    Player *mySecondPlayer;
};

#endif // GAME_H
