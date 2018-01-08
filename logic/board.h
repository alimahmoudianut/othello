#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include "logic/cell.h"

class Board
{
public:
    Board(unsigned int col = 8, unsigned int row = 8);

    Cell *getCell(int r, int c) const;
    unsigned int getRowNum() const;
    unsigned int getColNum() const;
    vector<Cell*> getPossibleMovements(int color) const;

    void setRowNum(unsigned int n);
    void setColNum(unsigned int n);

    std::string printBoard() const;

private:
    std::vector<Cell*> myCells;
    unsigned int myRowNum;
    unsigned int myColNum;

};

#endif // BOARD_H
