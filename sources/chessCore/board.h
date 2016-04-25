#ifndef BOARD_H
#define BOARD_H
#include"figures.h"


class Board
{
public:
    Board();

    void addFigure(Figure* fig);
    void removeFigure(Cell& pos);
    void selectFigure(Cell& cell);
    void changePosition(Cell& pos1, Cell& pos2);
    bool isFigureSelected();
    Figure* getFigure(Cell& pos);

private:
    Figure* pFigures[8][8];
    Figure* selectedFigure;

};

#endif // BOARD_H
