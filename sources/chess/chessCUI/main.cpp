#include "board.h"
#include <iostream>
#include <stdlib.h>

using namespace std;



void getFigureType(Figure* fig)
{
    bool color;
    Pawn* pPawn = dynamic_cast<Pawn*>(fig);
    if (pPawn)
    {
        color = fig->getColor();
        if(color == 0)
            cout << "BP";
        else
            cout << "WP";
    }

    Knight* pKnight = dynamic_cast<Knight*>(fig);
    if (pKnight)
    {
        color = fig->getColor();
        if (color == 0)
            cout << "BK";
        else
            cout << "WK";
    }

    Bishop* pBishop = dynamic_cast<Bishop*>(fig);
    if (pBishop)
    {
        color = fig->getColor();
        if(color == 0)
            cout << "BB";
        else
            cout << "WB";
    }

    Rook* pRook = dynamic_cast<Rook*>(fig);
    if (pRook)
    {
        color = fig->getColor();
        if(color == 0)
            cout << "BR" ;
        else
            cout << "WR";
    }

    King* pKing = dynamic_cast<King*>(fig);
    if (pKing)
    {
        color = fig->getColor();
        if(color == 0)
            cout << "KB";
        else
            cout << "KW";
    }

    Queen* pQueen = dynamic_cast<Queen*>(fig);
    if (pQueen)
    {
        color = fig->getColor();
        if(color == 0)
            cout << "BQ";
        else
            cout << "WQ" ;
    }

    if (fig == 0)
        cout << " ";
    //cout << "_";
}

void startGame()
{
    Board board;
    //string desk[9][9];
    int i,j;
    //Cell pos(i,j);
    Figure* fig;

   /* for(i=0;i<9;i++)
    {
        desk[0][i] = i;
        desk[i][0] = i;
    }*/

    for(j = 0; j < 8; j++){
        for (i = 0; i < 8; i++){
            fig = board.getFigure(i,j);
            getFigureType(fig);
            cout << " ";
        }
        cout << endl;
    }

}

int main()
{
    cout << "1. Start a Chess Game " << endl;
    cout << "2. Exit " << endl;
    int inputValue = 3;
    while (inputValue != 0)
    {
        cin >> inputValue;
        switch(inputValue)
        {

        case 1:
            startGame();

        default:
            cout << "Incorrect input value" << endl;
        }
    }

    /*Board board;
    Figure* fig;
    Cell pos(0,7);

    fig = board.getFigure(0,7);
    Cell pos1(fig->getPosition());
    cout << pos1.getX()<< endl << pos1.getY(); */
}

