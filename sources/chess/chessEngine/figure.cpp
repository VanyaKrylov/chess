#include "figures.h"

//TODO переименовать файл в figures, чтобы совпадал с хэдером.

//Все данные методы дублируют друг друга на 100%. Но они находятся в разных классах, так что в отдельный метод их не вынести.
//На помощь приходит наследование.
//TODO вынести реализацию setPosition в отдельный класс и унаследоваться от него.
//Можно добавить реализацию прямо в класс Figure.
//Либо можно сделать класс типа AbstractFigure и вынести в него только интерфейс. А в Figure будет общая реализация.

void Pawn::setPosition(const Cell &cell)
{
    Pos.setX(cell.getX());
    Pos.setY(cell.getY());
}

void Knight::setPosition(const Cell &cell)
{
    Pos.setX(cell.getX());
    Pos.setY(cell.getY());
}

void Bishop::setPosition(const Cell &cell)
{
    Pos.setX(cell.getX());
    Pos.setY(cell.getY());
}

void Rook::setPosition(const Cell &cell)
{
    Pos.setX(cell.getX());
    Pos.setY(cell.getY());
}

void King::setPosition(const Cell &cell)
{
    Pos.setX(cell.getX());
    Pos.setY(cell.getY());
}

void Queen::setPosition(const Cell &cell)
{
    Pos.setX(cell.getX());
    Pos.setY(cell.getY());
}

