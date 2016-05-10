#ifndef CELL_H
#define CELL_H
#include "exceptions.h"



class Cell
{

public:
    Cell(int x, int y) : x(x), y(y) {}

    Cell(const Cell& cell);

    int getX() const { return x; }

    void setX(const int x) { this->x=x; }

    int getY() const { return y; }

    void setY(const int y) { this->y=y; }

private:

    int x;
    int y;

};

#endif // CELL_H
