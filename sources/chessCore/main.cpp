#include "board.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

void startGame()
{
    Board board();
    string desk[9][9];
    int i = 0,j = 0;
    Cell pos(i,j);

    for(i=0;i<9;i++)
    {
        desk[0][i] = i;
    }

    for(i = 1; i < 9; i++)
    {
        for (j = 1; j < 9; j++)
        {
            desk[i+1][j+1] = getFigureType(board.getFigure(pos));
        }
    }



}

string getFigureType(Figure* fig)
{
    bool color;
    Pawn* pPawn = dynamic_cast<Pawn*>(fig);
    if (pPawn)
    {
        color = fig->getColor();
        if(color == 0)
            return "BP";
        else
            return "WP";
    }

    Knight* pKnight = dynamic_cast<Knight*>(fig);
    if (pKnight)
    {
        color = fig->getColor();
        if (color == 0)
            return "BK";
        else
            return "WK";
    }

    Bishop* pBishop = dynamic_cast<Bishop*>(fig);
    if (pBishop)
    {
        color = fig->getColor();
        if(color == 0)
            return "BB";
        else
            return "WB";
    }

    Rook* pRook = dynamic_cast<Rook*>(fig);
    if (pRook)
    {
        color = fig->getColor();
        if(color == 0)
            return "BR";
        else
            return "WR";
    }

    King* pKing = dynamic_cast<King*>(fig);
    if (pKing)
    {
        color = fig->getColor();
        if(color == 0)
            return "BK";
        else
            return "WK";
    }

    Queen* pQueen = dynamic_cast<Queen*>(fig);
    if (pQueen)
    {
        color = fig->getColor();
        if(color == 0)
            return "BQ";
        else
            return "WQ";
    }
    return 0;
}


int main()
{
    cout << "1. Start a Chess Game";
    cout << "2. Exit ";
    int inputValue = 0;
    while (inputValue != 0)
    {
        switch(inputValue)
        {

        case 1:
            startGame();
        }
    }
}

