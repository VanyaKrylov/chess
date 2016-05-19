#ifndef EXCEPTIONS
#define EXCEPTIONS
#include <exception>




class OutOfBoardException : public std::exception
{

public:   
    const char * what() {return "Wrong coordinates of the position. Moved out of the board";}

};

class FigureNotSelectedException : public std::exception
{

public:
    const char* what() {return "No figure selected";}

};

class SameColorFigureException : public std::exception
{
public:
    const char * what() {return "You can not attack your own figures";}
};

class EmptyCellExceprion : public std::exception
{
public:
    const char * what() {return "This cell is empty";}
};

class AgainstTheRulesException : std::exception
{
public:
    const char * what() {return "You can not move this figure like this. See the game's rules";}
};

class BadDenominatorException : std::exception
{
public:
    const char * what() {return "Denominator can't be 0";}
};

#endif // EXCEPTIONS

