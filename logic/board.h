#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include "logic/cell.h"

class Board
{
public:
    Board(unsigned int col = 8, unsigned int row = 8);
    Board(std::string str, unsigned int row = 8, unsigned int col = 8);
    ~Board();

    Cell *getCell(int r, int c) const;
    unsigned int getRowNum() const;
    unsigned int getColNum() const;
    std::vector<Cell *> getAllPossibleMovements(int color) const;\
    std::vector<Cell *> getCellsByPieceColor(int color) const;
    std::vector<Cell *> getCellsBetweenInLine(Cell *c1, Cell *c2) const;
    int getDistanceBetweenInLine(Cell *c1, Cell *c2) const;
    int getPoint(int color) const;

    bool isPossibleMovement(Cell *c, int color) const;
    bool isInOneLine(Cell *c1, Cell *c2) const;
    bool isJump(Cell *c1, Cell *c2, int color) const;
    int makeJump(Cell *c1, Cell *c2, int color);

    void setRowNum(unsigned int n);
    void setColNum(unsigned int n);
    int addMovement(int row, int col, int color);

    std::string toStr() const;
    std::string toString() const;
    std::string deepToString() const;

private:
    int addMovementUpdates(Cell *c, int color);
    std::string getAllPossibleMovementsStr(int color) const;\


    static unsigned int maxi(unsigned int a, unsigned int b);
    static unsigned int mini(unsigned int a, unsigned int b);

    std::vector<Cell *> myCells;
    unsigned int myRowNum;
    unsigned int myColNum;

};

#endif // BOARD_H
