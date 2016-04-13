#ifndef FIGURE_H
#define FIGURE_H
#include <vector>
#include "cell.h"


/**
 * @brief The Figure class - abstract class for figures
 */
class Figure
{
public:

    /**
     * @brief getColor - shows the color of the current figure
     * @return boolean value of the color. 0 - black, 1 - white
     */
    virtual bool getColor()=0;

    /**
     * @brief setColor - sets the color of the current figure
     * @param color: 0 - black, 1 - white
     */
    virtual void setColor(bool color)=0;

    /**
     * @brief checkPossibleMoves - gives a list of possible moves for current figure according to the rules of the game
     * @param ArrayOfMoves - vector of Cells - possible positions to move current figure
     */
    virtual void checkPossibleMoves(vector<Cell> &ArrayOfMoves)=0;

    /**
     * @brief ~Figure - destructor
     */
    virtual ~Figure(){}

};

class Pawn:public Figure
{
public:
    Pawn(bool);
    ~Pawn();

    void setColor(bool color);
    bool getColor();
    int getFigureType();
    void checkPossibleMoves(vector<Cell> &ArrayOfMoves);

private:
    bool Color;
};



class Knight:public Figure
{
public:
    Knight(bool);
    ~Knight();

    void setColor(bool color);
    bool getColor();
    int getFigureType();
    void checkPossibleMoves(vector<Cell> &ArrayOfMoves);

private:
    bool Color;
};



class Bishop:public Figure
{
public:
    Bishop(bool);
    ~Bishop();

    void setColor(bool color);
    bool getColor();
    int getFigureType();
    void checkPossibleMoves(vector<Cell> &ArrayOfMoves);

private:
    bool Color;
};



class Rook:public Figure
{
public:
    Rook(bool);
    ~Rook();

    void setColor(bool color);
    bool getColor();
    int getFigureType();
    void checkPossibleMoves(vector<Cell> &ArrayOfMoves);

private:
    bool Color;
};



class King:public Figure
{
public:
    King(bool);
    ~King();

    void setColor(bool color);
    bool getColor();
    int getFigureType();
    void checkPossibleMoves(vector<Cell> &ArrayOfMoves);

private:
    bool Color;
};



class Queen:public Figure
{
public:
    Queen(bool);
    ~Queen();

    void setColor(bool color);
    bool getColor();
    int getFigureType();
    void checkPossibleMoves(vector<Cell> &ArrayOfMoves);

private:
    bool Color;
};
#endif // FIGURE_H
