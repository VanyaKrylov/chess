#ifndef CELL_H
#define CELL_H
#include "figures.h"


class Cell
{

public:
    Cell();

    int getX();
    void setX(int x);
    int getY();
    void setY(int y);

private:

    int x;
    int y;

};

#endif // CELL_H
