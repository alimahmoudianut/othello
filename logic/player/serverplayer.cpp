#include "serverplayer.h"
#include <sstream>
using namespace std;

ServerPlayer::ServerPlayer(int color, string name)
    :Player(color , name)
{

}

string ServerPlayer::play(Board const * const board)
{

}

string ServerPlayer::deepToString(int i) const
{

    Player::deepToString(i);

}
