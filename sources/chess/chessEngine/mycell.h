#pragma once
#ifndef MYCELL_H
#define MYCELL_H







/**
 * @brief The myCell class
 */
class myCell
{

public:


    myCell(int x, int y)  : x(x), y(y) {}
    

    myCell(const myCell& cell);
    

    /**
     * @brief getXval - get x value
     * @return x position
     */
    int getXval() const { return x; }
    

    /**
     * @brief setXval - set x value
     * @param x
     */
    void setXval(const int x) { this->x=x; }
    

    /**
     * @brief getYval - get y value
     * @return y position
     */
    int getYval() const  { return y; }
    

    /**
     * @brief setYval - set y value
     * @param y - y position
     */
    void setYval(const int y)  { this->y=y; }

private:

    int x;
    int y;

};

#endif // MYCELL_H
