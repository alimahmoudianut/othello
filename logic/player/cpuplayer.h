#ifndef CPUPLAYER_H
#define CPUPLAYER_H

#include "logic/player.h"
#include <sstream>
using namespace std;

class CpuPlayer : public Player
{
public:
    CpuPlayer(int color, string name = "CPU Player");

    string play(Board const * const board);
};

#endif // CPUPLAYER_H
