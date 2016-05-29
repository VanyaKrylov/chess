#ifndef APPLICATION_H
#define APPLICATION_H
#include "API.h"
#include <iostream>
#include <string>
//cstdlib
#include <stdlib.h>
//TODO убрать using namecpace std; сам Страуструп даже говорит так делать.
using namespace std;

//TODO добавить const noexcept, где надо.

class Game
{
public:

    Game();

    void menu();

    void startGame();

    std::string getFigureType(myFigure* fig);

    void printBoard();

    void printMenu(int menuType) const;

    int letterToInt(const char letter);



private:
    ChessEngine core;
    
    //TODO bool -> enum
    bool color;

};

#endif // APPLICATION_H
