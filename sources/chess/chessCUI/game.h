#ifndef APPLICATION_H
#define APPLICATION_H
#include "API.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;


class Game
{
public:

    Game();

    void menu();

    void startGame();

    std::string getFigureType(Figure* fig);

    void printBoard();

    void printMenu(int menuType) const;



private:
    ChessEngine core;
    bool color;

};

#endif // APPLICATION_H
