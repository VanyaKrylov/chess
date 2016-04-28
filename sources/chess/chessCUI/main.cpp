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
        //return "P";

        color = fig->getColor();
        if(color == 0)
            return "BP";
        else
            return "WP";
    }

    Knight* pKnight = dynamic_cast<Knight*>(fig);
    if (pKnight)
    {
        //return "k";

        color = fig->getColor();
        if (color == 0)
            cout << "BK";
        else
            cout << "WK";
    }

    Bishop* pBishop = dynamic_cast<Bishop*>(fig);
    if (pBishop)
    {

        //return "B";

        color = fig->getColor();
        if(color == 0)
            cout << "BB";
        else
            cout << "WB";
    }

    Rook* pRook = dynamic_cast<Rook*>(fig);
    if (pRook)
    {
        //return "R";

        color = fig->getColor();
        if(color == 0)
            return "BR" ;
        else
            return"WR";
    }

    King* pKing = dynamic_cast<King*>(fig);
    if (pKing)
    {
        //return "K";

        color = fig->getColor();
        if(color == 0)
            return "KB";
        else
            return "KW";
    }

    Queen* pQueen = dynamic_cast<Queen*>(fig);
    if (pQueen)
    {
        //return "Q";

        color = fig->getColor();
        if(color == 0)
            return "BQ";
        else
            return "WQ" ;
    }

    if (fig == 0)
        return "__";
    //cout << "_";
}

void startGame()
{
    Board board;
    //char* FigType;
    bool color;
    //char desk[9][9];
    int i,j;

    Figure* fig;

    for(j=1;j<8;++j){
        for(i=0;i<8;i++){
            fig = board.getFigure(i,j);
            //FigType = getFigureType(fig);
            cout << getFigureType(fig) << " ";

            /*color = fig->getColor();
            if(color == 0)
                cout << "B";
            else
                cout << "W";
            cout << FigType <<" ";*/
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
            startGame(); break;

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

