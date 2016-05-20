#include "board.h"

//Слишком длинный метод.
//TODO разбить на более маленькие методы.
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
    
    //лучше инициализировать переменную все же. через список инициализации
    SelectedFigure = nullptr;
}

void Board::selectFigure(Cell *cell)
{
    int x,y;
    x = cell->getX();
    y = cell->getY();
    Cell pos(x,y);
    SelectedFigure = pFigures[x][y];
    SelectedFigure->setPosition(pos);
}

void Board::changePosition(Cell* pos)
{
    int x0,y0,x,y;
    Cell* selected_figure_position = SelectedFigure->getPosition();
    x0 = selected_figure_position->getX();
    y0 = selected_figure_position->getY();
    x = pos->getX();
    y = pos->getY();
    Cell cell(x,y);
    pFigures[x0][y0]->setPosition(cell);
    pFigures[x][y] = SelectedFigure;
    //Когда выделяешь память из кучи с помощью new, а потом присваиваешь nullptr, не освободив занятую память с помощью delete
    //, то случается, что ее уже нельзя освободить. утечка.
    //Попробуй еще валгриндом прогнать приложение. походи различным образом. по идее, он должен подтвердить
    //TODO пофиксить утечку
    pFigures[x0][y0] = nullptr;
    SelectedFigure = nullptr;

}

Figure* Board::getFigure(Cell *pos)
{
    int x,y;
    x = pos->getX();
    y = pos->getY();
    return pFigures[x][y];
}

bool Board::isFigureSelected()
{
    if (SelectedFigure == nullptr)
        return 0;
    else
        return 1;
    
    //лучше использовать true и false, чтобы не заставлять компилятор самостоятельно преобразовывать из int в bool.
       
    //а лучше так:
    //return SelectedFigure != nullptr;
}

void Board::addFigure(Figure *fig)
{
    int x,y;
    x = (fig->getPosition())->getX();
    y = (fig->getPosition())->getY();
    if ( (x>7) || (y>7) || (x<0) || (y<0) )
        throw OutOfBoardException();
    else
        pFigures[x][y] = fig;
}

void Board::removeFigure(Cell *pos)
{
    int x,y;
    x = pos->getX();
    y = pos->getY();
    if ( (x>7) || (y>7) || (x<0) || (y<0) )
        throw OutOfBoardException();
    else
        //Тут возможна утечка, т.к без delete.
        pFigures[x][y] = nullptr;

}

Figure* Board::getSelectedFigure()
{
    return SelectedFigure;
}


//Нереально длинный метод.
//TODO разбить на более короткие методы.
//CheckPawnPossibleMoves()
//CheckKnightPossibleMoves()
//и т.д.


//TODO заменить 1 и 0 на true и false
bool Board::CheckPossibleMoves(Cell *pos)
{
    bool color;
    int x,y,x0,y0;
    int count = 0;
    x0 = (SelectedFigure->getPosition())->getX();
    y0 = (SelectedFigure->getPosition())->getY();
    x = pos->getX();
    y = pos->getY();


    Pawn* pPawn = dynamic_cast<Pawn*>(SelectedFigure);
    if (pPawn)
    {

        color = SelectedFigure->getColor();
        if((x==x0) && (y==y0+1) && (getFigure(pos) == nullptr) && (color == 0))
            return 1;

        if((x==x0) && (y==y0-1) && (getFigure(pos) == nullptr) && (color == 1))
            return 1;

        if( (x == x0+1) && (y == y0+1) && (getFigure(pos) != nullptr) )
            if( (getFigure(pos)->getColor()) != color)
                return 1;

        if( (x == x0-1) && (y == y0+1) && (getFigure(pos) != nullptr) )
            if( (getFigure(pos)->getColor()) != color)
                return 1;

        return 0;
    }

    Knight* pKnight = dynamic_cast<Knight*>(SelectedFigure);
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

    Bishop* pBishop = dynamic_cast<Bishop*>(SelectedFigure);
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

    Rook* pRook = dynamic_cast<Rook*>(SelectedFigure);
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

    /*King* pKing = dynamic_cast<King*>(SelectedFigure);
    if (pKing)
    {

    }

    Queen* pQueen = dynamic_cast<Queen*>(SelectedFigure);
    if (pQueen)if(pFigures[x0][y0] != nullptr)
    {

        color = SelectedFigure->getColor();
        if(color == 0)
            return "BQ";
        else
            return "WQ" ;
    }*/
    return 1; //dolzhen byt' 0
}

//Когда добавишь delete в классы выше, для избежания утечек, здесь придется проверять была ли уже освобождена память,
//чтобы не освободить ее 2 раза. А это очень плохо, сам знаешь.
Board::~Board()
{
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            delete pFigures[i][j];
        }
    }
}
