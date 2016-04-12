#ifndef FIGURE_H
#define FIGURE_H
#include <vector>
#include "cell.h"

/*struct Cell
{
    int x;
    int y;
};*/

class Figure
{
public:

    //virtual void moveTo(PositionOnBoard& pos)=0;
    virtual bool getColor()=0;
    virtual bool setColor()=0;
    virtual void checkPossibleMoves(vector<Cell> &ArrayOfMoves)=0;
    virtual ~Figure(){}

};

class Pawn:public Figure
{
public:
    Pawn(bool);
    ~Pawn();

    bool getColor();
    int getFigureType();

private:
    bool Color;
};

#endif // FIGURE_H
