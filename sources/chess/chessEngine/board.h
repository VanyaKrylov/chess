#ifndef BOARD_H
#define BOARD_H
#include"figures.h"


class Board
{
public:
    Board();
    ~Board();

    /**
     * @brief addFigure - adding a figure to the board
     * @param fig - pointer to Figure object
     */
    void addFigure(Figure* fig);

    /**
     * @brief removeFigure - replaces figure from the current place on the board with a nullptr
     * @param pos - reference to Cell object of the figure's position
     */
    void removeFigure(Cell& pos);

    /**
     * @brief selectFigure - select a figure, changes the selectedFigure value
     * @param cell
     */
    void selectFigure(Cell& cell);

    /**
     * @brief changePosition - moves the selectedFigure to pos2
     * @param pos2 - reference to Cell object, contains the position
     */
    void changePosition(Cell& pos);

    /**
     * @brief isFigureSelected - checks whether there is any Figure selected
     * @return bool value, TRUE - selected, FALSE - not selected
     */
    bool isFigureSelected();

    /**
     * @brief getFigure - gets the Figure from the array
     * @param x -
     * @param y
     * @return pointer to Figure object
     */
    Figure* getFigure(int x, int y);

    /**
     * @brief getSelectedFigure - returns the selected figure
     * @return returns pointer to the SelectedFigure
     */
    Figure* getSelectedFigure();

private:
    Figure* pFigures[8][8];
    Figure* SelectedFigure;

};

#endif // BOARD_H
