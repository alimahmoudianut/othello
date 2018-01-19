#include "humanplayer.h"
#include <iostream>

HumanPlayer::HumanPlayer(int color, string name)
    :Player(color, name)
{

}

void HumanPlayer::play(Board *board)
{
    int ret;
    do
    {
        std::string input;
        std::cout << board->deepToString();
        std::cout << "Player #" << getID() << " (" << getColorStr() << ") movement : ";
        std::cin >> input;
        ret = board->addMovement(input[1]-'1', input[0]-'A', getColor());
    } while(ret);
}
