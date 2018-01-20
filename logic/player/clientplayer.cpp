#include "clientplayer.h"

ClientPlayer::ClientPlayer(int color, string name)
    :Player(color, name)
{

}

void ClientPlayer::play(Board *board)
{

}

string ClientPlayer::deepToString(int i) const
{
    stringstream out;
    out << Player::deepToString(i);
    return out.str();

}
