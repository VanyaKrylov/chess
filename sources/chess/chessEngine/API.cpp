#include "API.h"

//TODO убрать. Такой и сам сгенерируется компилятором
ChessEngine::ChessEngine()
{
}



void ChessEngine::chooseMyFigure(int x, int y)
{
    if( (x>7) || (y>7) || (x<0) || (y<0) )
        throw OutOfBoardException();
    myCell pos(x,y);
    if((chessBoard.getMyFigure(&pos)) == nullptr)
        throw EmptyCellException();
    else{
        chessBoard.selectMyFigure(&pos);
    }
}

void ChessEngine::moveMyFigure(int x,int y)
{
    if( (x>7) || (y>7) || (x<0) || (y<0) )
        throw OutOfBoardException();
    else{
        myCell pos(x,y);
        myFigure* fig = chessBoard.getMyFigure(&pos);
        if(fig!=nullptr)
        {
            if(((chessBoard.getSelectedFigure())->getFigColor()) == (fig->getFigColor()))
                throw SameColorFigureException();
            if(chessBoard.checkPossibleMoves(&pos) == 0)
                throw AgainstTheRulesException();
            else{
                chessBoard.changeMyFigPosition(&pos);
            }
        }
        else{
            if(chessBoard.checkPossibleMoves(&pos) == 0)
                throw AgainstTheRulesException();
            chessBoard.changeMyFigPosition(&pos);

        }
    }
}

myFigure* ChessEngine::getMyFigure(int x, int y)
{
    if( (x>7) || (y>7) || (x<0) || (y<0) )
        throw OutOfBoardException();
    else{
        myCell pos(x,y);
        return chessBoard.getMyFigure(&pos);
    }
}

bool ChessEngine::isFigureSelected()
{
    return chessBoard.isMyFigureSelected();
}
