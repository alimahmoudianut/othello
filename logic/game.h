#ifndef GAME_H
#define GAME_H

#include "logic/board.h"
#include "logic/player.h"
#include "logic/player/humanplayer.h"
#include <string>
using namespace std;

#define TERMINAL_SERVER 0
#define TERMINAL_CLIENT 1
#define TERMINAL_OFFLINE 2

class Game
{
public:
    Game(int type = TERMINAL_OFFLINE);

    void start();
    void setFirstPlayer(Player *firstPlayer);
    void setSecondPlayer(Player *secondPlayer);

    string toString() const;
    string toDeepString() const;

private:
    Board *myBoard;
    Player *myFirstPlayer;
    Player *mySecondPlayer;

    int myID;
    static int ourCnt;

};

#endif // GAME_H
