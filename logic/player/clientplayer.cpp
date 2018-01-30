#include "clientplayer.h"
#include <iostream>
using namespace std;

ClientPlayer::ClientPlayer(int color, string name, QTcpSocket * socket)
    :Player(color, name)
{
    mySocket = socket;
}

string ClientPlayer::play(Board const * const board)
{
    if(this->getColor() == WHITE)
        mySocket->write("your turn");
    else
        mySocket->write("your turn");
}

string ClientPlayer::deepToString(int i) const
{
    stringstream out;
    out << Player::deepToString(i);
    return out.str();

}
