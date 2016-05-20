#ifndef CELL_H
#define CELL_H

//Не нашел исключений в этом классе.
//TODO убрать лишний хэдер
#include "exceptions.h"


//TODO документировать класс. http://www.stack.nl/~dimitri/doxygen/manual/docblocks.html
class Cell
{

public:
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    //У Мейерса объяснено более подробно, почему так надо сделать.
    Cell(int x, int y) : x(x), y(y) {}
    
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    Cell(const Cell& cell);
    
    //TODO добавить спецификатор const, т.к метод не изменяет состояния объекта класса.
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    int getX() const { return x; }
    
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    void setX(const int x) { this->x=x; }
    
    //TODO добавить спецификатор const, т.к метод не изменяет состояния объекта класса.
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    int getY() const { return y; }
    
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    void setY(const int y) { this->y=y; }

private:

    int x;
    int y;

};

#endif // CELL_H
