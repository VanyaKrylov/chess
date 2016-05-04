#include "board.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;



std::string getFigureType(Figure* fig)
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
            return "BR" ;
        else
            return "WR";
    }

    King* pKing = dynamic_cast<King*>(fig);
    if (pKing)
    {

        color = fig->getColor();
        if(color == 0)
            return "KB";
        else
            return "KW";
    }

    Queen* pQueen = dynamic_cast<Queen*>(fig);
    if (pQueen)
    {

        color = fig->getColor();
        if(color == 0)
            return "BQ";
        else
            return "WQ" ;
    }

    if (fig == nullptr)
        return "__";

}

void startGame()
{
    Board board;

    int i,j;

    Figure* fig = 0;

    cout << "  A  B  C  D  E  F  G  H" << endl;
    for(j=0;j<8;j++){
        cout << j+1 << " ";
        for(i=0;i<8;i++){
            fig = board.getFigure(i,j);
            cout << getFigureType(fig) << " ";
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
            cout << "Press 2 to exit" << endl; break;

        case 2:
            inputValue = 0; break;

        default:
            cout << "Incorrect input value" << endl;
            cout << "1. Start a Chess Game " << endl;
            cout << "2. Exit " << endl;
        }

    }
    cout << "Goodbye!" << endl;

    /*Board board;
    Figure* fig;
    Cell pos(0,7);

    fig = board.getFigure(0,7);
    Cell pos1(fig->getPosition());
    cout << pos1.getX()<< endl << pos1.getY(); */
}

