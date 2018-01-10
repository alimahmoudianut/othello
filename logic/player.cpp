#include "player.h"

int Player::ourCnt = 0;

Player::Player(int color)
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
