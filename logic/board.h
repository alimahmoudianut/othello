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
    std::vector<Cell *> getAllPossibleMovements(int color) const;\
    std::vector<Cell *> getCellsByPieceColor(int color) const;
    std::vector<Cell *> getCellsBetweenInLine(Cell *c1, Cell *c2) const;
    int getDistanceBetweenInLine(Cell *c1, Cell *c2) const;


    bool isPossibleMovement(Cell *c, int color) const;
    bool isInOneLine(Cell *c1, Cell *c2) const;


    void setRowNum(unsigned int n);
    void setColNum(unsigned int n);

    std::string printBoard() const;

private:
    static unsigned int maxi(unsigned int a, unsigned int b);
    static unsigned int mini(unsigned int a, unsigned int b);

    std::vector<Cell *> myCells;
    unsigned int myRowNum;
    unsigned int myColNum;

};

#endif // BOARD_H
