#include "player.h"
#include <sstream>
using namespace std;

int Player::ourCnt = 0;

Player::Player(int color, string name)
    : myID(ourCnt++)
{
    setColor(color);
}

int Player::getColor() const
{
    return myColor;
}

std::string Player::getColorStr() const
{
    std::string ret;
    if(getColor() == WHITE)
        return "white";
    else
        return "black";
}

int Player::getID() const
{
    return myID;
}

void Player::setColor(int color)
{
    myColor = color;
}

string Player::toString() const
{
    stringstream out;
    out << "PLAYER " << myID << endl;
    return out.str();
}
