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
    virtual bool getColor() const = 0;

    /**
     * @brief setColor - sets the color of the current figure
     * @param color: 0 - black, 1 - white
     */
    virtual void setColor(const bool color) = 0;

    /**
     * @brief checkPossibleMoves - gives a list of possible moves for current figure according to the rules of the game
     * @param ArrayOfMoves - vector of Cells - possible positions to move current figure
     */
    virtual void checkPossibleMoves(vector<Cell> &ArrayOfMoves)=0;

    /**
     * @brief getPosition - the position on the Board of the current figure
     * @return reference to cell
     */
    virtual Cell& getPosition() const = 0;

    /**
     * @brief setPosition - sets position of the current figure
     * @param cell - position on board
     */
    virtual void setPosition(const Cell &cell)=0;

    /**
     * @brief ~Figure - destructor
     */
    virtual ~Figure(){}

};

class Pawn:public Figure
{
public:
    Pawn(bool, Cell&);
    ~Pawn();

    void setColor(const bool color) { this->Color=color; }

    bool getColor() const { return Color; }

    Cell& getPosition() const { return Pos; }

    void checkPossibleMoves(vector<Cell> &ArrayOfMoves);

    void setPosition(const Cell &cell);

private:
    bool Color;
    Cell Pos;
};



class Knight:public Figure
{
public:
    Knight(bool, Cell&);
    ~Knight();

    void setColor(bool color);
    bool getColor();
    int getFigureType();
    void checkPossibleMoves(vector<Cell> &ArrayOfMoves);
    Cell& getPosition();
    void setPosition(Cell &cell);

private:
    bool Color;
    Cell Pos;
};



class Bishop:public Figure
{
public:
    Bishop(bool, Cell&);
    ~Bishop();

    void setColor(bool color);
    bool getColor();
    int getFigureType();
    void checkPossibleMoves(vector<Cell> &ArrayOfMoves);
    Cell& getPosition();
    void setPosition(Cell &cell);

private:
    bool Color;
    Cell Pos;
};



class Rook:public Figure
{
public:
    Rook(bool, Cell&);
    ~Rook();

    void setColor(bool color);
    bool getColor();
    int getFigureType();
    void checkPossibleMoves(vector<Cell> &ArrayOfMoves);
    Cell& getPosition();
    void setPosition(Cell &cell);

private:
    bool Color;
    Cell Pos;
};



class King:public Figure
{
public:
    King(bool, Cell&);
    ~King();

    void setColor(bool color);
    bool getColor();
    int getFigureType();
    void checkPossibleMoves(vector<Cell> &ArrayOfMoves);
    Cell& getPosition();
    void setPosition(Cell &cell);

private:
    bool Color;
    Cell Pos;
};



class Queen:public Figure
{
public:
    Queen(bool, Cell&);
    ~Queen();

    void setColor(bool color);
    bool getColor();
    int getFigureType();
    void checkPossibleMoves(vector<Cell> &ArrayOfMoves);
    Cell& getPosition();
    void setPosition(Cell &cell);

private:
    bool Color;
    Cell Pos;
};
#endif // FIGURE_H
