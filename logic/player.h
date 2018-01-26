#ifndef PLAYER_H
#define PLAYER_H

#include "logic/piece.h"
#include "logic/board.h"
#include <string>
#include <QObject>
using namespace std;

class Player
{
public:
    Player(int color, string name);

    int getColor() const;
    string getColorStr() const;
    int getID() const;
    string getName() const;

    void setColor(int color);

    virtual void play(Board *board) = 0;

    string toString() const;
    virtual string deepToString(int i = 1, int type = 1) const;

private:
    int myColor;
    string myName;

    int myID;
    static int ourCnt;
};

#endif // PLAYER_H
