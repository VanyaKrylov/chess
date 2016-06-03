#pragma once
#ifndef FIGURES_H
#define FIGURES_H
#include "mycell.h"


//Как я поянл, реализация всех методов классов, унаследованных от Figure, совпадает на 100%.
//TODO не нужно дублировать код. Нужно эту общую реализацию вынести в отдельный класс.
//Написал про это еще в cpp.

/**
 * @brief The myFigure class - abstract class for chess figures
 */
class myFigure
{
public:


    


    /**
     * @brief getFigColor - shows the color of the figure
     * @return bool value, 0 - black, 1 - white
     */
    virtual bool getFigColor() const = 0;




    /**
     * @brief setFigColor sets the color for current figure
     * @param color - 0 - black, 1 - white
     */
    virtual void setFigColor(const bool color) = 0;

    
    /**
     * @brief getFigPosition - gets figure position
     * @return myCell object
     */
    virtual myCell* getFigPosition()   = 0;

    /**
     * @brief setFigPosition sets figure position
     * @param cell - myCell object
     */
    virtual void setFigPosition(const myCell &cell)  =0;


    virtual ~myFigure()  {}

};




class Pawn: public myFigure
{
public:

    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    Pawn(bool color, myCell& pos) : Color(color), Pos(pos) {}
    ~Pawn(){}

    void setFigColor(const bool color)  override { this->Color=color; }

    bool getFigColor() const override{ return Color; }
       
    myCell* getFigPosition()   override { return &Pos; }
       
    void setFigPosition(const myCell &cell) override;
    

    
private:
    //Мне кажется диким - использовать тип bool для цвета.
    //TODO сделать enum
    //насколько мне известно, неконстантные объекты любого класса принято называть с маленькой буквы
    //TODO  подумать над стилем
    bool Color;
    myCell Pos;
};

//Все замечания к предыдущим классам относятся и к тем, что ниже.
//TODO const noexcept override bool->enum

class Knight: public myFigure
{
public:
    Knight(bool color, myCell& pos) : Color(color), Pos(pos) {}
    ~Knight(){}

    void setFigColor(const bool color)  override { this->Color=color; }

    bool getFigColor() const override{ return Color; }

    myCell* getFigPosition()   override { return &Pos; }

    void setFigPosition(const myCell &cell) override;

private:
    bool Color;
    myCell Pos;
};



class Bishop: public myFigure
{
public:
    Bishop(bool color, myCell& pos) : Color(color), Pos(pos) {}
    ~Bishop(){}

    void setFigColor(const bool color)  override { this->Color=color; }

    bool getFigColor() const override{ return Color; }

    myCell* getFigPosition()   override { return &Pos; }

    void setFigPosition(const myCell &cell) override;


private:
    bool Color;
    myCell Pos;
};



class Rook: public myFigure
{
public:
    Rook(bool color, myCell& pos) : Color(color), Pos(pos) {}
    ~Rook(){}

    void setFigColor(const bool color)  override { this->Color=color; }

    bool getFigColor() const override{ return Color; }

    myCell* getFigPosition()   override { return &Pos; }

    void setFigPosition(const myCell &cell) override;


private:
    bool Color;
    myCell Pos;
};



class King: public myFigure
{
public:
    King(bool color, myCell& pos) : Color(color), Pos(pos) {}
    ~King(){}

    void setFigColor(const bool color)  override { this->Color=color; }

    bool getFigColor() const override{ return Color; }

    myCell* getFigPosition()   override { return &Pos; }

    void setFigPosition(const myCell &cell) override;


private:
    bool Color;
    myCell Pos;
};



class Queen: public myFigure
{
public:
    Queen(bool color, myCell& pos) : Color(color), Pos(pos) {}
    ~Queen(){}

    void setFigColor(const bool color)  override { this->Color=color; }

    bool getFigColor() const override{ return Color; }

    myCell* getFigPosition()   override { return &Pos; }

    void setFigPosition(const myCell &cell) override;

private:
    bool Color;
    myCell Pos;
};
#endif // FIGURES_H
