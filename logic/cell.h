#ifndef CELL_H
#define CELL_H

#include <string>
#include "logic/piece.h"
#include "view/boardtexture.h"

class Cell
{
public:
    Cell(int r, int c);

    int getRowNum() const;
    int getColNum() const;
    std::string getLabel() const;
    std::string getPieceSign() const;
    Piece *getPiece() const;
    int getTexture() const;

    void setRowNum(const int r);
    void setColNum(const int c);
    void setPiece(Piece *piece);

    bool isEmpty();

    std::string toString() const;
    std::string deepToString() const;

private:
    int myRowNum;
    int myColNum;
    Piece *myPiece;
};

#endif // CELL_H
