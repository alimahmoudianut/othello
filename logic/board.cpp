#include "board.h"

#include <sstream>

Board::Board(unsigned int col, unsigned int row)
{
    // Initialize row and column numbers
    setRowNum(row);
    setColNum(col);

    // Initialize board, create cells
    for(unsigned int i = 0; i < getRowNum(); i++)
    {
        for(unsigned int j = 0; j < getColNum(); j++)
        {
            Cell *c = new Cell(i, j);
            myCells.push_back(c);
        }
    }
}

Cell *Board::getCell(int r, int c) const
{
    for(unsigned int i = 0; i < myCells.size(); i++)
        if((myCells[i]->getRowNum() == r) &&
           (myCells[i]->getColNum() == c))
            return myCells[i];
    return NULL;
}

unsigned int Board::getRowNum() const
{
    return myRowNum;
}

unsigned int Board::getColNum() const
{
    return myColNum;
}

void Board::setRowNum(unsigned int n)
{
    myRowNum = n;
}

void Board::setColNum(unsigned int n)
{
    myColNum = n;
}

std::string Board::printBoard() const
{
    std::stringstream out;
    for(unsigned int i = 0; i < getRowNum(); i++)
    {
        for(unsigned int j = 0; j < getColNum(); j++)
        {
            out << getCell(i, j)->getLabel() << " ";
        }
        out << std::endl;
    }
    return out.str();
}
