#include "serverplayer.h"
#include <sstream>
using namespace std;

ServerPlayer::ServerPlayer(int color, string name)
    :Player(color , name)
{

}

void ServerPlayer::play(Board *board)
{

}

string ServerPlayer::deepToString(int i) const
{

    Player::deepToString(i);

}
