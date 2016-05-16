#include "API.h"


ChessEngine::ChessEngine()
{

}

void ChessEngine::chooseFigure(int x, int y)
{

    if( (x>7) || (y>7) || (x<0) || (y<0) )
        throw OutOfBoardException();
    else{
        Cell pos(x,y);
        board.selectFigure(&pos);
    }
}

void ChessEngine::moveFigure(int x,int y)
{
    if( (x>7) || (y>7) || (x<0) || (y<0) )
        throw OutOfBoardException();
    else{
        Cell pos(x,y);
        Figure* fig = board.getFigure(&pos);
        if(fig!=nullptr)
        {
            if(((board.getSelectedFigure())->getColor()) == (fig->getColor()))
                throw SameColorFigureException();
            else{
                board.changePosition(&pos);
            }
        }
        else
            board.changePosition(&pos);
    }
}

Figure* ChessEngine::getFigure(int x, int y)
{
    if( (x>7) || (y>7) || (x<0) || (y<0) )
        throw OutOfBoardException();
    else{
        Cell pos(x,y);
        return board.getFigure(&pos);
    }
}
