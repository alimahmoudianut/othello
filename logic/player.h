#ifndef PLAYER_H
#define PLAYER_H

#include "logic/piece.h"
#include "logic/board.h"
#include <string>
using namespace std;

class Player
{
public:
    Player(int color, string name);

    int getColor() const;
    std::string getColorStr() const;
    int getID() const;

    void setColor(int color);

    virtual void play(Board *board) = 0;

    string toString() const;

private:
    int myColor;
    string myName;

    int myID;
    static int ourCnt;
};

#endif // PLAYER_H
