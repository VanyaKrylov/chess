#ifndef EXCEPTIONS
#define EXCEPTIONS
#include <exception>




class OutOfBoardException : public std::exception
{

public:

    OutOfBoardException(int x, int y): x(x), y(y) {}

    int getX(){return x;}

    int getY(){return y;}

    const char * what() {return "Wrong coordinates of the position. Moved out of the board";}

private:
    int x;
    int y;

};

class FigureNotSelectedException : public std::exception
{

public:
    const char* what() {return "No figure selected";}

};

#endif // EXCEPTIONS

