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

    void start(int detail = 0);
    void setFirstPlayer(Player *firstPlayer);
    void setSecondPlayer(Player *secondPlayer);
    void setLastMovement(string mv, Player *player);

    Player *getFirstPlayer() const;
    Player *getSecondPlayer() const;
    string getLastMovement() const;
    int getNumberOfPlayers() const;

    int isPlayerTurn(Player *player) const;


    string toString() const;
    string deepToString() const;

    int addMovement(string mv, Player *player);

    int getTurn() const;
    int getID() const;

private:
    void calculateNextTurn();

    Board *myBoard;
    Player *myFirstPlayer;
    Player *mySecondPlayer;
    string myLastMovement;
    int myTurn;


    int myID;
    static int ourCnt;

};

#endif // GAME_H
