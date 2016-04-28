#include "board.h"


Board::Board()
{
    int i,j;
    bool color = 0;
    Cell pos(0,0);

    pFigures[0][0] = new Rook(color,pos);

    pos.setX(1);
    pFigures[1][0] = new Knight(color,pos);

    pos.setX(2);
    pFigures[2][0] = new Bishop(color,pos);

    pos.setX(3);
    pFigures[3][0] = new Queen(color,pos);

    pos.setX(4);
    pFigures[4][0] = new King(color,pos);

    pos.setX(7);
    pFigures[7][0] = new Rook(color,pos);

    pos.setX(6);
    pFigures[6][0] =  new Knight(color,pos);

    pos.setX(5);
    pFigures[5][0] = new Bishop(color,pos);

    for (i=0; i<8; i++)
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

    for (i=0; i<8; i++)
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

Figure* Board::getFigure(int x, int y)
{
    /*int x,y;
    x = x.getX();
    y = x.getY();*/
    return pFigures[x][y];
}
