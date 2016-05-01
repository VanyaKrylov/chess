#ifndef APPLICATION_H
#define APPLICATION_H
#include "board.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;


class Game
{
public:
    Game();

    void menu();

private:
    Board board;
    Figure* fig;

};

#endif // APPLICATION_H
