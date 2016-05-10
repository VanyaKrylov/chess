#include "API.h"


ChessEngine::ChessEngine()
{

}

void ChessEngine::chooseFigure(Cell &pos)
{

    if( (pos.getX()>7) || (pos.getY()>7) || (pos.getX()<0) || (pos.getY()<0) )
        throw OutOfBoardException(pos.getX(),pos.getY());
    else
        board.selectFigure(pos);
}

void ChessEngine::moveFigure(Cell &pos)
{
    if(board.isFigureSelected() == 0)
        throw FigureNotSelectedException();
    else
        board.changePosition(pos);
}
