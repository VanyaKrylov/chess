#pragma once
#ifndef FIGURES_H
#define FIGURES_H
#include "mycell.h"


//Как я поянл, реализация всех методов классов, унаследованных от Figure, совпадает на 100%.
//TODO не нужно дублировать код. Нужно эту общую реализацию вынести в отдельный класс.
//Написал про это еще в cpp.

/**
 * @brief The Figure class - abstract class for figures
 */
class myFigure
{
public:

    /**
     * @brief getColor - shows the color of the current figure
     * @return boolean value of the color. 0 - black, 1 - white
     */
    
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    virtual bool getFigColor() const = 0;

    /**
     * @brief setColor - sets the color of the current figure
     * @param color: 0 - black, 1 - white
     */
    
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    virtual void setFigColor(const bool color) = 0;

    //virtual Figure* operator = (Figure* fig) = 0;

    /**
     * @brief getPosition - the position on the Board of the current figure
     * @return reference to cell
     */
    
    //TODO добавить спецификатор const, т.к метод не изменяет состояния объекта класса.
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    virtual myCell* getFigPosition() = 0;

    /**
     * @brief setPosition - sets position of the current figure
     * @param cell - position on board
     */
    
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    virtual void setFigPosition(const myCell &cell)=0;

    /**
     * @brief ~Figure - destructor
     */
    
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    virtual ~myFigure(){}

};

    //TODO добавить спецификатор const, т.к метод не изменяет состояния объекта класса.
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    //TODO добавить спецификатор override, т.к реализация данного метода меняется по отношению к суперклассу std::exception
    //У Мейерса объяснено более подробно, почему так надо сделать.

//От всех классов ниже ты ведь не наследуешься. Поэтому не нужно деструктор объявлять даже невиртуальный. Он и так сам сгенерируется.


class Pawn: public myFigure
{
public:

    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    Pawn(bool color, myCell& pos) : Color(color), Pos(pos) {}
    ~Pawn(){}
    
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    //TODO добавить спецификатор override, т.к реализация данного метода меняется по отношению к суперклассу Figure
    void setFigColor(const bool color) { this->Color=color; }
    
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    //TODO добавить спецификатор override, т.к реализация данного метода меняется по отношению к суперклассу std::exception
    bool getFigColor() const { return Color; }
    
    //TODO добавить спецификатор const, т.к метод не изменяет состояния объекта класса.
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    //TODO добавить спецификатор override, т.к реализация данного метода меняется по отношению к суперклассу std::exception
    myCell* getFigPosition() { return &Pos; }
    
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    //TODO добавить спецификатор override, т.к реализация данного метода меняется по отношению к суперклассу Figure
    void setFigPosition(const myCell &cell);
    
    //Кусок кода закомментированный. TODO убрать или допилить
    //Figure* operator =(Figure* fig){
    
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

    void setFigColor(const bool color) { this->Color=color; }

    bool getFigColor() const { return Color; }

    myCell* getFigPosition() { return &Pos; }

    void setFigPosition(const myCell &cell);


private:
    bool Color;
    myCell Pos;
};



class Bishop: public myFigure
{
public:
    Bishop(bool color, myCell& pos) : Color(color), Pos(pos) {}
    ~Bishop(){}

    void setFigColor(const bool color) { this->Color=color; }

    bool getFigColor() const { return Color; }

    myCell* getFigPosition() { return &Pos; }

    void setFigPosition(const myCell &cell);


private:
    bool Color;
    myCell Pos;
};



class Rook: public myFigure
{
public:
    Rook(bool color, myCell& pos) : Color(color), Pos(pos) {}
    ~Rook(){}

    void setFigColor(const bool color) { this->Color=color; }

    bool getFigColor() const { return Color; }

    myCell* getFigPosition() { return &Pos; }

    void setFigPosition(const myCell &cell);


private:
    bool Color;
    myCell Pos;
};



class King: public myFigure
{
public:
    King(bool color, myCell& pos) : Color(color), Pos(pos) {}
    ~King(){}

    void setFigColor(const bool color) { this->Color=color; }

    bool getFigColor() const { return Color; }

    myCell* getFigPosition() { return &Pos; }

    void setFigPosition(const myCell &cell);


private:
    bool Color;
    myCell Pos;
};



class Queen: public myFigure
{
public:
    Queen(bool color, myCell& pos) : Color(color), Pos(pos) {}
    ~Queen(){}

    void setFigColor(const bool color) { this->Color=color; }

    bool getFigColor() const { return Color; }

    myCell* getFigPosition() { return &Pos; }

    void setFigPosition(const myCell &cell);


private:
    bool Color;
    myCell Pos;
};
#endif // FIGURES_H
