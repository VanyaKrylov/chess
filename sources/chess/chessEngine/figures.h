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

    //virtual Figure* operator = (Figure* fig) = 0;

    /**
     * @brief getPosition - the position on the Board of the current figure
     * @return reference to cell
     */
    virtual Cell* getPosition() = 0;

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

class Pawn: public Figure
{
public:
    Pawn(bool color, Cell& pos) : Color(color), Pos(pos) {}
    ~Pawn(){}

    void setColor(const bool color) { this->Color=color; }

    bool getColor() const { return Color; }

    Cell* getPosition() { return &Pos; }

    void setPosition(const Cell &cell);

    //Figure* operator =(Figure* fig){
private:
    bool Color;
    Cell Pos;
};



class Knight: public Figure
{
public:
    Knight(bool color, Cell& pos) : Color(color), Pos(pos) {}
    ~Knight(){}

    void setColor(const bool color) { this->Color=color; }

    bool getColor() const { return Color; }

    Cell* getPosition() { return &Pos; }

    void setPosition(const Cell &cell);


private:
    bool Color;
    Cell Pos;
};



class Bishop: public Figure
{
public:
    Bishop(bool color, Cell& pos) : Color(color), Pos(pos) {}
    ~Bishop(){}

    void setColor(const bool color) { this->Color=color; }

    bool getColor() const { return Color; }

    Cell* getPosition() { return &Pos; }

    void setPosition(const Cell &cell);


private:
    bool Color;
    Cell Pos;
};



class Rook: public Figure
{
public:
    Rook(bool color, Cell& pos) : Color(color), Pos(pos) {}
    ~Rook(){}

    void setColor(const bool color) { this->Color=color; }

    bool getColor() const { return Color; }

    Cell* getPosition() { return &Pos; }

    void setPosition(const Cell &cell);


private:
    bool Color;
    Cell Pos;
};



class King: public Figure
{
public:
    King(bool color, Cell& pos) : Color(color), Pos(pos) {}
    ~King(){}

    void setColor(const bool color) { this->Color=color; }

    bool getColor() const { return Color; }

    Cell* getPosition() { return &Pos; }

    void setPosition(const Cell &cell);


private:
    bool Color;
    Cell Pos;
};



class Queen: public Figure
{
public:
    Queen(bool color, Cell& pos) : Color(color), Pos(pos) {}
    ~Queen(){}

    void setColor(const bool color) { this->Color=color; }

    bool getColor() const { return Color; }

    Cell* getPosition() { return &Pos; }

    void setPosition(const Cell &cell);


private:
    bool Color;
    Cell Pos;
};
#endif // FIGURE_H
