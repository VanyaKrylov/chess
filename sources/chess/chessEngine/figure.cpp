#include "figures.h"

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

bool Pawn::checkPossibleMoves()
{

}

bool Bishop::checkPossibleMoves()
{

}

bool Rook::checkPossibleMoves()
{

}

bool Knight::checkPossibleMoves()
{

}

bool King::checkPossibleMoves()
{

}

bool Queen::checkPossibleMoves()
{

}
