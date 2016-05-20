#ifndef EXCEPTIONS
#define EXCEPTIONS
#include <exception>



//TODO документировать класс. http://www.stack.nl/~dimitri/doxygen/manual/docblocks.html
class OutOfBoardException : public std::exception
{

public:
    //TODO добавить спецификатор const, т.к метод не изменяет состояния объекта класса.
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    //TODO добавить спецификатор override, т.к реализация данного метода меняется по отношению к суперклассу std::exception
    //У Мейерса объяснено более подробно, почему так надо сделать.
    //const char * what() const noexcept override { ... }
    const char * what() {return "Wrong coordinates of the position. Moved out of the board";}

};

//TODO документировать класс
class FigureNotSelectedException : public std::exception
{

public:
    //TODO добавить спецификатор const, т.к метод не изменяет состояния объекта класса.
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    //TODO добавить спецификатор override, т.к реализация данного метода меняется по отношению к суперклассу std::exception
    //У Мейерса объяснено более подробно, почему так надо сделать.
    const char* what() {return "No figure selected";}

};

//TODO документировать класс
class SameColorFigureException : public std::exception
{
public:
    //TODO добавить спецификатор const, т.к метод не изменяет состояния объекта класса.
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    //TODO добавить спецификатор override, т.к реализация данного метода меняется по отношению к суперклассу std::exception
    //У Мейерса объяснено более подробно, почему так надо сделать.
    const char * what() {return "You can not attack your own figures";}
};

//TODO документировать класс
class EmptyCellException : public std::exception
{
public:
    //TODO добавить спецификатор const, т.к метод не изменяет состояния объекта класса.
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    //TODO добавить спецификатор override, т.к реализация данного метода меняется по отношению к суперклассу std::exception
    //У Мейерса объяснено более подробно, почему так надо сделать.
    const char * what() {return "This cell is empty";}
};

//TODO документировать класс
class AgainstTheRulesException : std::exception
{
public:
    //TODO добавить спецификатор const, т.к метод не изменяет состояния объекта класса.
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    //TODO добавить спецификатор override, т.к реализация данного метода меняется по отношению к суперклассу std::exception
    //У Мейерса объяснено более подробно, почему так надо сделать.
    const char * what() {return "You can not move this figure like this. See the game's rules";}
};

//TODO документировать класс
//Странное исключение. Интересно, для чего?
class BadDenominatorException : std::exception
{
public:
    //TODO добавить спецификатор const, т.к метод не изменяет состояния объекта класса.
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    //TODO добавить спецификатор override, т.к реализация данного метода меняется по отношению к суперклассу std::exception
    //У Мейерса объяснено более подробно, почему так надо сделать.
    const char * what() {return "Denominator can't be 0";}
};

#endif // EXCEPTIONS

