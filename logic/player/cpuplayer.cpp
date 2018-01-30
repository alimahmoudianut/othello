#include "cpuplayer.h"

CpuPlayer::CpuPlayer(int color, string name)
    :Player(color, name)
{

}

string CpuPlayer::play(const Board * const board)
{
    return board->getAllPossibleMovements(getColor())[0]->getLabel();
}
