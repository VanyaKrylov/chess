#include "boardLogic.h"

//Слишком длинный метод.
//TODO разбить на более маленькие методы.
BoardLogic::BoardLogic()
{
    int i,j;
    bool color = 0;
    myCell pos(0,0);

    pos.setXval(0);
    pos.setYval(0);
    pFigures[0][0] = new Rook(color,pos);

    pos.setXval(1);
    pFigures[1][0] = new Knight(color,pos);

    pos.setXval(2);
    pFigures[2][0] = new Bishop(color,pos);

    pos.setXval(3);
    pFigures[3][0] = new Queen(color,pos);

    pos.setXval(4);
    pFigures[4][0] = new King(color,pos);

    pos.setXval(7);
    pFigures[7][0] = new Rook(color,pos);

    pos.setXval(6);
    pFigures[6][0] =  new Knight(color,pos);

    pos.setXval(5);
    pFigures[5][0] = new Bishop(color,pos);

    for (i=0; i<8; i++)
    {
        pos.setYval(1);
        pos.setXval(i);
        pFigures[i][1] = new Pawn(color,pos);
    }


    color = 1;
    pos.setXval(0);
    pos.setYval(7);
    pFigures[0][7] = new Rook(color,pos);

    pos.setXval(1);
    pFigures[1][7] = new Knight(color,pos);

    pos.setXval(2);
    pFigures[2][7] = new Bishop(color,pos);

    pos.setXval(3);
    pFigures[3][7] = new Queen(color,pos);

    pos.setXval(4);
    pFigures[4][7] = new King(color,pos);

    pos.setXval(7);
    pFigures[7][7] = new Rook(color,pos);

    pos.setXval(6);
    pFigures[6][7] =  new Knight(color,pos);

    pos.setXval(5);
    pFigures[5][7] = new Bishop(color,pos);

    for (i=0; i<8; i++)
    {
        pos.setYval(6);
        pos.setXval(i);
        pFigures[i][6] = new Pawn(color,pos);
    }

    for(j=2; j<6; j++)
    {
        for(i=0;i<8;i++)
        {
            pFigures[i][j] = nullptr;
        }
    }
    
    //лучше инициализировать переменную все же. через список инициализации
    selectedFigure = nullptr;

    previousFigColor = 0;
}

void BoardLogic::changePreviousColor()
{
    if (previousFigColor == 0)
        previousFigColor = 1;
    else
        previousFigColor = 0;
}

void BoardLogic::selectMyFigure(myCell *cell)
{
    int x,y;
    x = cell->getXval();
    y = cell->getYval();
    if(pFigures[x][y]->getFigColor() == previousFigColor)
        throw WrongColorMoveException();
    myCell pos(x,y);
    selectedFigure = pFigures[x][y];
    selectedFigure->setFigPosition(pos);
    changePreviousColor();
}

void BoardLogic::changeMyFigPosition(myCell* pos)
{
    int x0,y0,x,y;
    myCell* selected_figure_position = selectedFigure->getFigPosition();
    x0 = selected_figure_position->getXval();
    y0 = selected_figure_position->getYval();
    x = pos->getXval();
    y = pos->getYval();
    myCell cell(x,y);
    myFigure *checkIfKing = pFigures[x][y];
    pFigures[x0][y0]->setFigPosition(cell);
    pFigures[x][y] = selectedFigure;
    //Когда выделяешь память из кучи с помощью new, а потом присваиваешь nullptr, не освободив занятую память с помощью delete
    //, то случается, что ее уже нельзя освободить. утечка.
    //Попробуй еще валгриндом прогнать приложение. походи различным образом. по идее, он должен подтвердить
    //TODO пофиксить утечку
    pFigures[x0][y0] = nullptr;
    selectedFigure = nullptr;
    King* pKing = dynamic_cast<King*>(checkIfKing);
    if (pKing)
    {
        throw KingKilledException();
    }

}

myFigure* BoardLogic::getMyFigure(myCell *pos)
{
    int x,y;
    x = pos->getXval();
    y = pos->getYval();
    return pFigures[x][y];
}

bool BoardLogic::isMyFigureSelected()
{
    if (selectedFigure == nullptr)
        return 0;
    else
        return 1;
    
    //лучше использовать true и false, чтобы не заставлять компилятор самостоятельно преобразовывать из int в bool.
       
    //а лучше так:
    //return SelectedFigure != nullptr;
}

/*void BoardLogic::addMyFigure(myFigure *fig)
{
    int x,y;
    x = (fig->getFigPosition())->getXval();
    y = (fig->getFigPosition())->getYval();
    if ( (x>7) || (y>7) || (x<0) || (y<0) )
        throw OutOfBoardException();
    else
        pFigures[x][y] = fig;
}

void BoardLogic::removeMyFigure(myCell *pos)
{
    int x,y;
    x = pos->getXval();
    y = pos->getYval();
    if ( (x>7) || (y>7) || (x<0) || (y<0) )
        throw OutOfBoardException();
    else
        //Тут возможна утечка, т.к без delete.
        pFigures[x][y] = nullptr;

}*/

myFigure* BoardLogic::getSelectedFigure()
{
    return selectedFigure;
}


//Нереально длинный метод.
//TODO разбить на более короткие методы.
//CheckPawnPossibleMoves()
//CheckKnightPossibleMoves()
//и т.д.


//TODO заменить 1 и 0 на true и false
bool BoardLogic::checkPossibleMoves(myCell *pos)
{
    bool color;
    int x,y,x0,y0;
    int count = 0;
    x0 = (selectedFigure->getFigPosition())->getXval();
    y0 = (selectedFigure->getFigPosition())->getYval();
    x = pos->getXval();
    y = pos->getYval();


    Pawn* pPawn = dynamic_cast<Pawn*>(selectedFigure);
    if (pPawn)
    {

        color = selectedFigure->getFigColor();
        if((x==x0) && (y==y0+1) && (getMyFigure(pos) == nullptr) && (color == 0))
            return 1;

        if((x==x0) && (y==y0-1) && (getMyFigure(pos) == nullptr) && (color == 1))
            return 1;

        if( (x == x0+1) && (y == y0+1) && (getMyFigure(pos) != nullptr) )
            if( (getMyFigure(pos)->getFigColor()) != color)
                return 1;

        if( (x == x0-1) && (y == y0+1) && (getMyFigure(pos) != nullptr) )
            if( (getMyFigure(pos)->getFigColor()) != color)
                return 1;

        if( (x == x0+1) && (y == y0-1) && (getMyFigure(pos) != nullptr) )
            if( (getMyFigure(pos)->getFigColor()) != color)
                return 1;

        if( (x == x0-1) && (y == y0-1) && (getMyFigure(pos) != nullptr) )
            if( (getMyFigure(pos)->getFigColor()) != color)
                return 1;

        if((y0==6) | (y0==1))
        {
            if((x==x0) && (y==y0+2) && (getMyFigure(pos) == nullptr) && (color == 0))
                return 1;

            if((x==x0) && (y==y0-2) && (getMyFigure(pos) == nullptr) && (color == 1))
                return 1;
        }

        return 0;
    }

    Knight* pKnight = dynamic_cast<Knight*>(selectedFigure);
    if (pKnight)
    {

        if( (x==x0-1) && (y == y0+2) )
            return 1;

        if( (x==x0+1) && (y == y0+2) )
            return 1;

        if( (x==x0+2) && (y == y0-1) )
            return 1;

        if( (x==x0+2) && (y == y0+1) )
            return 1;

        if( (x==x0-1) && (y == y0-2) )
            return 1;

        if( (x==x0+1) && (y == y0-2) )
            return 1;

        if( (x==x0-2) && (y == y0-1) )
            return 1;

        if( (x==x0-2) && (y == y0+1) )
            return 1;

        return 0;
    }

    Bishop* pBishop = dynamic_cast<Bishop*>(selectedFigure);
    if (pBishop)
    {

        if ( (fabs(y-y0)) / (fabs(x-x0) ) == 1)
        {
            while( (x0 < x) && (y0 < y) ){
                if( (pFigures[x0][y0] != nullptr) && (count != 0) )
                    return 0;
                x0++;
                y0++;
                count++;
                if( (x0 == x) && (y0 == y) )
                    return 1;
            }

            while( (x0 < x) && (y0 > y) ){
                if( (pFigures[x0][y0] != nullptr) && (count != 0) )
                    return 0;
                x0++;
                y0--;
                count++;
                if( (x0 == x) && (y0 == y) )
                    return 1;
            }

            while( (x0 > x) && (y0 < y) ){
                if( (pFigures[x0][y0] != nullptr) && (count != 0) )
                    return 0;
                x0--;
                y0++;
                count++;
                if( (x0 == x) && (y0 == y) )
                    return 1;
            }

            while( (x0 > x) && (y0 > y) ){
                if( (pFigures[x0][y0] != nullptr) && (count != 0) )
                    return 0;
                x0--;
                y0--;
                count++;
                if( (x0 == x) && (y0 == y) )
                    return 1;
            }
        }
        return 0;
    }

    Rook* pRook = dynamic_cast<Rook*>(selectedFigure);
    if (pRook)
    {
        if(x0==x)
        {
            while(y0 > y){
                if( (pFigures[x0][y0] != nullptr) && (count != 0) )
                    return 0;
                y0--;
                count++;
                if(y0==y)
                    return 1;
            }

            while(y0 < y){
                if( (pFigures[x0][y0] != nullptr) && (count != 0) )
                    return 0;
                y0++;
                count++;
                if(y0==y)
                    return 1;
            }
        }

        if(y0==y)
        {
            while(x0 > x){
                if( (pFigures[x0][y0] != nullptr) && (count != 0) )
                    return 0;
                x0--;
                count++;
                if(x0==x)
                    return 1;
            }

            while(x0 < x){
                if( (pFigures[x0][y0] != nullptr) && (count != 0) )
                    return 0;
                x0++;
                count++;
                if(x0==x)
                    return 1;
            }
        }
        return 0;
    }

    King* pKing = dynamic_cast<King*>(selectedFigure);
    if (pKing)
    {

        if(x0 == x)
        {
            if(y==y0+1)
                return 1;
            if(y==y0-1)
                return 1;
        }

        if(y0==y)
        {
            if(x==x0+1)
                return 1;
            if(x==x0-1)
                return 1;
        }

        if(x == x0+1)
        {
            if(y==y0+1)
                return 1;
            if(y==y0-1)
                return 1;
        }

        if(x == x0-1)
        {
            if(y==y0+1)
                return 1;
            if(y==y0-1)
                return 1;
        }

        return 0;
    }

    Queen* pQueen = dynamic_cast<Queen*>(selectedFigure);
    if (pQueen)if(pFigures[x0][y0] != nullptr)
    {

        if ( (fabs(y-y0)) / (fabs(x-x0) ) == 1)
        {
            while( (x0 < x) && (y0 < y) ){
                if( (pFigures[x0][y0] != nullptr) && (count != 0) )
                    return 0;
                x0++;
                y0++;
                count++;
                if( (x0 == x) && (y0 == y) )
                    return 1;
            }

            while( (x0 < x) && (y0 > y) ){
                if( (pFigures[x0][y0] != nullptr) && (count != 0) )
                    return 0;
                x0++;
                y0--;
                count++;
                if( (x0 == x) && (y0 == y) )
                    return 1;
            }

            while( (x0 > x) && (y0 < y) ){
                if( (pFigures[x0][y0] != nullptr) && (count != 0) )
                    return 0;
                x0--;
                y0++;
                count++;
                if( (x0 == x) && (y0 == y) )
                    return 1;
            }

            while( (x0 > x) && (y0 > y) ){
                if( (pFigures[x0][y0] != nullptr) && (count != 0) )
                    return 0;
                x0--;
                y0--;
                count++;
                if( (x0 == x) && (y0 == y) )
                    return 1;
            }
        }

        if(x0==x)
        {
            while(y0 > y){
                if( (pFigures[x0][y0] != nullptr) && (count != 0) )
                    return 0;
                y0--;
                count++;
                if(y0==y)
                    return 1;
            }

            while(y0 < y){
                if( (pFigures[x0][y0] != nullptr) && (count != 0) )
                    return 0;
                y0++;
                count++;
                if(y0==y)
                    return 1;
            }
        }

        if(y0==y)
        {
            while(x0 > x){
                if( (pFigures[x0][y0] != nullptr) && (count != 0) )
                    return 0;
                x0--;
                count++;
                if(x0==x)
                    return 1;
            }

            while(x0 < x){
                if( (pFigures[x0][y0] != nullptr) && (count != 0) )
                    return 0;
                x0++;
                count++;
                if(x0==x)
                    return 1;
            }
        }
        return 0;
    }
    return 0;
}

//Когда добавишь delete в классы выше, для избежания утечек, здесь придется проверять была ли уже освобождена память,
//чтобы не освободить ее 2 раза. А это очень плохо, сам знаешь.
BoardLogic::~BoardLogic()
{
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            delete pFigures[i][j];
        }
    }
}
