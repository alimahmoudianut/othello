#ifndef CELL_H
#define CELL_H

#include <string>
#include "piece.h"

class Cell
{
public:
    Cell(int r, int c);

    int getRowNum() const;
    int getColNum() const;
    std::string getLabel() const;
    Piece *getPiece();

    void setRowNum(const int r);
    void setColNum(const int c);
    void setPiece(Piece *piece);

    std::string toString() const;
    std::string deepToString() const;

private:
    int myRowNum;
    int myColNum;
    Piece *myPiece;
};

#endif // CELL_H
