#ifndef PLAYER_H
#define PLAYER_H

#include "logic/piece.h"
#include "logic/board.h"

class Player
{
public:
    Player(int color);

    int getColor() const;
    std::string getColorStr() const;
    int getID() const;

    void setColor(int color);

    virtual void play(Board *board) = 0;

private:
    int myColor;

    int myID;
    static int ourCnt;
};

#endif // PLAYER_H
