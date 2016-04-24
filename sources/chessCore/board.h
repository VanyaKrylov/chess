#ifndef BOARD_H
#define BOARD_H
#include"figures.h"


class Board
{
public:
    Board();

    addFigure(Figure* fig);
    removeFigure(Cell& pos);
    changePosition(Cell& pos1, Cell& pos2);

private:
    Figure* pFigures[8][8];


};

#endif // BOARD_H
