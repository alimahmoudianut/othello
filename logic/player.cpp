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

string Player::deepToString(int i, int type) const
{
    stringstream out;
    if(type == 1)
        out << "*------------------------ PLAYER " << i << " ------------------------*" << endl;
    else
        out << setfill('*') << setw(60) << "" << endl;
    out << setfill(' ') << "* " << std::left << setw(57) << "" << "*" << endl;
    out << "* ID : " << std::left << setw(52) << getID()  << "*"  << endl;
    out << "* Name : " << std::left << setw(50) << getName()  << "*"  << endl;
    out << "* Color : " << std::left << setw(49) << getColorStr() << "*" << endl;
    if(type != 1)
    {
        out << setfill(' ') << "* " << std::left << setw(57) << "" << "*" << endl;
        out << setfill('*') << setw(60) << "" << endl;
    }
    return out.str();
}
