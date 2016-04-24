#include "board.h"


Board::Board()
{
    int i;
    bool color = 0;
    Cell pos(0,0);

    pFigures[0][0] = Rook(color,pos);

    pos.setX(1);
    pFigures[1][0] = Knight(color,pos);

    pos.setX(2);
    pFigures[2][0] = Bishop(color,pos);

    pos.setX(7);
    pFigures[7][0] = Rook(color,pos);

    pos.setX(6);
    pFigures[6][0] = Knight(color,pos);

    pos.setX(5);
    pFigures[5][0] = Bishop(color,pos);

    for (i=1; i<8; i++)
    {
        pos.setY(1);
        pos.setX(i);
        pFigures[i][1] = new Pawn(color,pos);
    }

    color = 1;
    pos.setX(0);
    pos.setY(7);
    pFigures[0][7] = Rook(color,pos);

    pos.setX(1);
    pFigures[1][7] = Knight(color,pos);

    pos.setX(2);
    pFigures[2][7] = Bishop(color,pos);

    pos.setX(7);
    pFigures[7][7] = Rook(color,pos);

    pos.setX(6);
    pFigures[6][7] = Knight(color,pos);

    pos.setX(5);
    pFigures[5][7] = Bishop(color,pos);

    for (i=1; i<8; i++)
    {
        pos.setY(6);
        pos.setX(i);
        pFigures[i][6] = new Pawn(color,pos);
    }
}

