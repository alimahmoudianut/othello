#ifndef CELL_H
#define CELL_H

#include <string>
#include "piece.h"

class Cell
{
public:
    Cell(int x, int y);

    int getAxisX() const;
    int getAxisY() const;
    std::string getLabel() const;
    Piece *getPiece();

    void setAxisX(const int x);
    void setAxisY(const int y);
    void setPiece(Piece *piece);

    std::string toString() const;
    std::string deepToString() const;

private:
    int myAxisX;
    int myAxisY;
    Piece *myPiece;
};

#endif // CELL_H
