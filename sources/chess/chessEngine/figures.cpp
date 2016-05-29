#include "figures.h"

//TODO переименовать файл в figures, чтобы совпадал с хэдером.

//Все данные методы дублируют друг друга на 100%. Но они находятся в разных классах, так что в отдельный метод их не вынести.
//На помощь приходит наследование.
//TODO вынести реализацию setPosition в отдельный класс и унаследоваться от него.
//Можно добавить реализацию прямо в класс Figure.
//Либо можно сделать класс типа AbstractFigure и вынести в него только интерфейс. А в Figure будет общая реализация.

void Pawn::setFigPosition(const myCell &cell)
{
    Pos.setXval(cell.getXval());
    Pos.setYval(cell.getYval());
}

void Knight::setFigPosition(const myCell &cell)
{
    Pos.setXval(cell.getXval());
    Pos.setYval(cell.getYval());
}

void Bishop::setFigPosition(const myCell &cell)
{
    Pos.setXval(cell.getXval());
    Pos.setYval(cell.getYval());
}

void Rook::setFigPosition(const myCell &cell)
{
    Pos.setXval(cell.getXval());
    Pos.setYval(cell.getYval());
}

void King::setFigPosition(const myCell &cell)
{
    Pos.setXval(cell.getXval());
    Pos.setYval(cell.getYval());
}

void Queen::setFigPosition(const myCell &cell)
{
    Pos.setXval(cell.getXval());
    Pos.setYval(cell.getYval());
}

