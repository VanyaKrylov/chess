#include "game.h"
#include <iostream>

Game::Game()
{

}

void Game::menu()
{

}

void Game::printBoard()
{
    int i,j;

    Figure* fig = 0;

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
