#pragma once
#ifndef MYCELL_H
#define MYCELL_H

//Не нашел исключений в этом классе.
//TODO убрать лишний хэдер



//TODO документировать класс. http://www.stack.nl/~dimitri/doxygen/manual/docblocks.html
class myCell
{

public:
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    //У Мейерса объяснено более подробно, почему так надо сделать.
    myCell(int x, int y) : x(x), y(y) {}
    
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    myCell(const myCell& cell);
    
    //TODO добавить спецификатор const, т.к метод не изменяет состояния объекта класса.
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    int getXval() const { return x; }
    
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    void setXval(const int x) { this->x=x; }
    
    //TODO добавить спецификатор const, т.к метод не изменяет состояния объекта класса.
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    int getYval() const { return y; }
    
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    void setYval(const int y) { this->y=y; }

private:

    int x;
    int y;

};

#endif // MYCELL_H
