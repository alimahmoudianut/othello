#include "humanplayer.h"
#include <iostream>

HumanPlayer::HumanPlayer(int color, string name)
    :Player(color, name)
{

}

string HumanPlayer::play(Board const * const board)
{
    int ret;
    do
    {
        std::string input;
        std::cout << "Player #" << getID() << " (" << getColorStr() << ") movement : ";
        std::cin >> input;
        Cell *c = board->getCell(input[1]-'1', input[0]-'A');
        if(board->isPossibleMovement(c, getColor()))
            return input;
    } while(ret);
}
