#include "board.h"


Board::Board()
{
    int i,j;
    bool color = 0;
    Cell pos(0,0);

    pos.setX(0);
    pos.setY(0);
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

    pos.setX(3);
    pFigures[3][7] = new King(color,pos);

    pos.setX(4);
    pFigures[4][7] = new Queen(color,pos);

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
            pFigures[i][j] = nullptr;
        }
    }

    selectedFigure = nullptr;
}

void Board::changePosition(Cell& pos)
{
    int x0,y0,x,y;
    Cell selected_figure_position(selectedFigure->getPosition());
    x0 = selected_figure_position.getX();
    y0 = selected_figure_position.getY();
    x = pos.getX();
    y = pos.getY();

    pFigures[x][y] = pFigures[x0][y0];
    pFigures[x0][y0] = nullptr;
    selectedFigure = nullptr;
}

Figure* Board::getFigure(int x, int y)
{
    /*int x,y;
    x = x.getX();
    y = x.getY();*/
    return pFigures[x][y];
}

Board::~Board()
{
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            delete pFigures[i][j];
        }
    }
}
