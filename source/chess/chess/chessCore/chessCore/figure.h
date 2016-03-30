#ifndef FIGURE_H
#define FIGURE_H

struct positionOnBoard
{
    int x;
    int y;
};

class figure
{
public:
    virtual positionOnBoard getPosition()=0;
    virtual void moveTo(positionOnBoard& pos)=0;
    virtual bool getColor()=0;
    virtual int getFigureType()=0;

};

#endif // FIGURE_H
