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

private:
    ChessEngine core;

};

#endif // APPLICATION_H
