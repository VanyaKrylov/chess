#include "game.h"
#include <iostream>

Game::Game()
{

}


std::string Game::getFigureType(Figure *fig)
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

void Game::printBoard()
{
    int i,j;

    Figure* fig = 0;

    if (color == 0)
        cout << "Black's move" << endl;
    else
        cout << "White's move" << endl;

    cout << "  A  B  C  D  E  F  G  H" << endl;
    for(j=0;j<8;j++){
        cout << j+1 << " ";
        for(i=0;i<8;i++){
            fig = core.getFigure(i,j);
            cout << getFigureType(fig) << " ";
        }
        cout << endl;
    }
}

void Game::menu()
{

    int menuType = 1;
    int inputValue = 3;
    printMenu(menuType);
    while (inputValue != 0)
    {

        printMenu(menuType);
        cin >> inputValue;
        switch(inputValue)
        {

        case 1:
            menuType = 2;
            printMenu(menuType);
            printBoard();

            break;

        case 0:
            inputValue = 0; break;

        default:
            cout << "Incorrect input value" << endl;
            break;
        }
    }
}

void Game::startGame()
{

    int
    while
}
