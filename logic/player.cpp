#include "player.h"
#include <sstream>
#include <iomanip>
using namespace std;

int Player::ourCnt = 0;

Player::Player(int color, string name)
    : myID(ourCnt++)
{
    setColor(color);
    myName = name;
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

string Player::getName() const
{
    return myName;
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

string Player::deepToString(int i) const
{
    stringstream out;
    out << "*------------------------ PLAYER " << i << " ------------------------*" << endl;
    out << setfill(' ') << "* " << std::left << setw(57) << "" << "*" << endl;
    out << "* Name : " << std::left << setw(50) << getName()  << "*"  << endl;
    out << "* Color : " << std::left << setw(49) << getColorStr() << "*" << endl;
    return out.str();
}
