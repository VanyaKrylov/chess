#pragma once
#ifndef EXCEPTIONS
#define EXCEPTIONS
#include <exception>




/**
 * @brief The OutOfBoardException class - exception class for moving out of board
 */
class OutOfBoardException : public std::exception
{

public:
    //TODO добавить спецификатор const, т.к метод не изменяет состояния объекта класса.
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    //TODO добавить спецификатор override, т.к реализация данного метода меняется по отношению к суперклассу std::exception
    //У Мейерса объяснено более подробно, почему так надо сделать.
    //const char * what() const noexcept override { ... }

    /**
     * @brief what - exception message
     * @return message of the error
     */
    const char * what() {return "Wrong coordinates of the position. Moved out of the board";}

};



/**
 * @brief The FigureNotSelectedException class -exception class for trying to move not selected figure
 */
class FigureNotSelectedException : public std::exception
{

public:
    //TODO добавить спецификатор const, т.к метод не изменяет состояния объекта класса.
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    //TODO добавить спецификатор override, т.к реализация данного метода меняется по отношению к суперклассу std::exception
    //У Мейерса объяснено более подробно, почему так надо сделать.

    /**
     * @brief what - exception message
     * @return message of the error
     */
    const char* what() {return "No figure selected";}

};


/**
 * @brief The SameColorFigureException class - exception class for trying to attack your own figure
 */
class SameColorFigureException : public std::exception
{
public:
    //TODO добавить спецификатор const, т.к метод не изменяет состояния объекта класса.
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    //TODO добавить спецификатор override, т.к реализация данного метода меняется по отношению к суперклассу std::exception
    //У Мейерса объяснено более подробно, почему так надо сделать.

    /**
     * @brief what- exception message
     * @return message of the error
     */
    const char * what() {return "You can not attack your own figures";}
};


/**
 * @brief The EmptyCellException class - exception class, when the empty cell is chosen
 */
class EmptyCellException : public std::exception
{
public:
    //TODO добавить спецификатор const, т.к метод не изменяет состояния объекта класса.
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    //TODO добавить спецификатор override, т.к реализация данного метода меняется по отношению к суперклассу std::exception
    //У Мейерса объяснено более подробно, почему так надо сделать.

    /**
     * @brief what- exception message
     * @return message of the error
     */
    const char * what() {return "This cell is empty";}
};


/**
 * @brief The AgainstTheRulesException class - exception class when the move is againstthe game logic
 */
class AgainstTheRulesException : std::exception
{
public:
    //TODO добавить спецификатор const, т.к метод не изменяет состояния объекта класса.
    //TODO добавить спецификатор noexcept, т.к метод не генерирует исключений.
    //TODO добавить спецификатор override, т.к реализация данного метода меняется по отношению к суперклассу std::exception
    //У Мейерса объяснено более подробно, почему так надо сделать.

    /**
     * @brief what- exception message
     * @return message of the error
     */
    const char * what() {return "You can not move this figure like this. See the game's rules";}
};


/**
 * @brief The WrongColorMoveException class
 */
class WrongColorMoveException : std::exception
{
public:
    /**
     * @brief what- exception message
     * @return message of the error
     */
    const char * what() {return "It is another's color turn to make a move";}
};

/**
 * @brief The KingKilledException class
 */
class KingKilledException : std::exception
{
public:
    /**
     * @brief what- exception message
     * @return message of the error
     */
    const char * what() {return "King killed. Game over";}
};

#endif // EXCEPTIONS

