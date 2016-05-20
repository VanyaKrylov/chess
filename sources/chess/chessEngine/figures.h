#ifndef FIGURE_H
#define FIGURE_H
#include <vector>
#include "cell.h"


//Как я поянл, реализация всех методов классов, унаследованных от Figure, совпадает на 100%.
//TODO не нужно дублировать код. Нужно эту общую реализацию вынести в отдельный класс.
//Написал про это еще в cpp.

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
    
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    virtual bool getColor() const = 0;

    /**
     * @brief setColor - sets the color of the current figure
     * @param color: 0 - black, 1 - white
     */
    
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    virtual void setColor(const bool color) = 0;

    //virtual Figure* operator = (Figure* fig) = 0;

    /**
     * @brief getPosition - the position on the Board of the current figure
     * @return reference to cell
     */
    
    //TODO добавить спецификатор const, т.к метод не изменяет состояния объекта класса.
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    virtual Cell* getPosition() = 0;

    /**
     * @brief setPosition - sets position of the current figure
     * @param cell - position on board
     */
    
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    virtual void setPosition(const Cell &cell)=0;

    /**
     * @brief ~Figure - destructor
     */
    
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    virtual ~Figure(){}

};

    //TODO добавить спецификатор const, т.к метод не изменяет состояния объекта класса.
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    //TODO добавить спецификатор override, т.к реализация данного метода меняется по отношению к суперклассу std::exception
    //У Мейерса объяснено более подробно, почему так надо сделать.

class Pawn: public Figure
{
public:

    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    Pawn(bool color, Cell& pos) : Color(color), Pos(pos) {}
    ~Pawn(){}
    
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    //TODO добавить спецификатор override, т.к реализация данного метода меняется по отношению к суперклассу Figure
    void setColor(const bool color) { this->Color=color; }
    
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    //TODO добавить спецификатор override, т.к реализация данного метода меняется по отношению к суперклассу std::exception
    bool getColor() const { return Color; }
    
    //TODO добавить спецификатор const, т.к метод не изменяет состояния объекта класса.
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    //TODO добавить спецификатор override, т.к реализация данного метода меняется по отношению к суперклассу std::exception
    Cell* getPosition() { return &Pos; }
    
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    //TODO добавить спецификатор override, т.к реализация данного метода меняется по отношению к суперклассу Figure
    void setPosition(const Cell &cell);
    
    //Кусок кода закомментированный. TODO убрать или допилить
    //Figure* operator =(Figure* fig){
    
private:
    //Мне кажется диким - использовать тип bool для цвета.
    //TODO сделать enum
    //насколько мне известно, неконстантные объекты любого класса принято называть с маленькой буквы
    //TODO  подумать над стилем
    bool Color;
    Cell Pos;
};

//Все замечания к предыдущим классам относятся и к тем, что ниже.
//TODO const noexcept override bool->enum

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
