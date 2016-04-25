#include "board.h"


Board::Board()
{
    int i,j;
    bool color = 0;
    Cell pos(0,0);

    Rook leftBlackRook(color,pos);
    pFigures[0][0] = &leftBlackRook;

    pos.setX(1);
    Knight leftBlackKnight(color,pos);
    pFigures[1][0] = &leftBlackKnight;

    pos.setX(2);
    Bishop leftBlackBishop(color,pos);
    pFigures[2][0] = &leftBlackBishop;

    pos.setX(7);
    Rook rightBlackRook(color,pos);
    pFigures[7][0] = &rightBlackRook;

    pos.setX(6);
    Knight rightBlackKnight(color,pos);
    pFigures[6][0] = &rightBlackKnight;

    pos.setX(5);
    Bishop rightBlackBishop(color,pos);
    pFigures[5][0] = &rightBlackBishop;

    for (i=1; i<8; i++)
    {
        pos.setY(1);
        pos.setX(i);
        pFigures[i][1] = new Pawn(color,pos);
    }

    color = 1;
    pos.setX(0);
    pos.setY(7);
    pFigures[0][7] = new Rook(color,pos);

    pos.setX(1);
    pFigures[1][7] = new Knight(color,pos);

    pos.setX(2);
    pFigures[2][7] = new Bishop(color,pos);

    pos.setX(7);
    pFigures[7][7] = new Rook(color,pos);

    pos.setX(6);
    pFigures[6][7] =  new Knight(color,pos);

    pos.setX(5);
    pFigures[5][7] = new Bishop(color,pos);

    for (i=1; i<8; i++)
    {
        pos.setY(6);
        pos.setX(i);
        pFigures[i][6] = new Pawn(color,pos);
    }

    for(j=2; j<6; j++)
    {
        for(i=0;i<8;i++)
        {
            pFigures[i][j] = 0;
        }
    }
}

void Board::changePosition(Cell &pos1, Cell &pos2)
{
    int x0,y0,x,y;

    x0 = pos1.getX();
    y0 = pos1.getY();
    x = pos2.getX();
    y = pos2.getY();

    pFigures[x][y] = pFigures[x0][y0];
    pFigures[x0][y0] = 0;
}

Figure* Board::getFigure(Cell &pos)
{
    int x,y;
    x = pos.getX();
    y = pos.getY();
    return pFigures[x][y];
}
