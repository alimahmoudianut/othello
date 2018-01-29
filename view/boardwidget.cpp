#include "boardwidget.h"
#include "view/boardtexture.h"
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include <iostream>
using namespace std;

static char PieceTypePics[LAST_TYPE][100] = {
    ":src/img/empty.png",
    ":src/img/whitePiece.png",
    ":src/img/blackPiece.png"
};

BoardWidget::BoardWidget(QWidget *parent, Game *game) : QWidget(parent)
{
    cout << "widget created" << endl;
    if(game == NULL)
        myGame = new Game();
    else
        myGame = game;
    myPadWidth = 10;
    myPadHeight = 10;

    myGapWidth = 5;
    myGapHeight = 5;

    myCellWidth = 50;
    myCellHeight = 50;

    QSize size((myCellHeight + myGapHeight) * myGame->getBoard()->getRowNum() - myGapHeight + 2 * myPadHeight
               , (myCellWidth + myGapWidth) * myGame->getBoard()->getColNum() - myGapWidth + 2 * myPadWidth);
    setMaximumSize(size);
    setMinimumSize(size);
}

void BoardWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);

    painter.fillRect(event->rect(), QColor(0, 0, 0));

    QSize size(myCellWidth, myCellHeight);

    for(unsigned int i = 0; i < myGame->getBoard()->getColNum(); i++)
    {
        for(unsigned int j = 0; j < myGame->getBoard()->getRowNum(); j++)
        {
            Cell *cell = myGame->getBoard()->getCell(i, j);
            QRect mRect(getCellXPos(i, j),
                        getCellYPos(i, j),
                        myCellWidth,
                        myCellHeight);
            QPixmap tmp(PieceTypePics[cell->getTexture()]);
            QPixmap pieceImage(tmp.scaled(size));
            painter.drawPixmap(mRect, pieceImage);

        }
    }

}

void BoardWidget::mousePressEvent(QMouseEvent *event)
{
    cout << "Mouse pressed!" << endl;
    Cell *cell = findCellByPoint(event->pos());
    if(cell == NULL)
        return;
    cout << cell->deepToString() << endl;
    if(myGame->getTurn() == WHITE)
        myGame->addMovement(cell->toString(), myGame->getFirstPlayer());
    else
        myGame->addMovement(cell->toString(), myGame->getSecondPlayer());
    cout << myGame->deepToString() << endl;
    update();
}

int BoardWidget::getCellXPos(int row, int col) const
{
    return col * (myCellWidth + myGapWidth) + myPadWidth;
}

int BoardWidget::getCellYPos(int row, int col) const
{
    return row * (myCellWidth + myGapWidth) + myPadWidth;
}

Cell *BoardWidget::findCellByPoint(const QPoint &point) const
{
    for(unsigned int i = 0; i < myGame->getBoard()->getColNum(); i++)
    {
        for(unsigned int j = 0; j < myGame->getBoard()->getRowNum(); j++)
        {
            if((point.x() >= getCellXPos(i, j))
              && (point.x() <= (getCellXPos(i, j) + myCellWidth))
              && (point.y() >= getCellYPos(i, j))
              && (point.y() <= (getCellYPos(i, j) + myCellHeight)))
            {
                return myGame->getBoard()->getCell(i, j);
            }
        }
    }
    return NULL;

}
