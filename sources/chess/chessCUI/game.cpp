#include "game.h"
#include <iostream>
#include <ios>


//TODO заменить списком инициализации
Game::Game()
{
    color = 1;
}

//Длинный метод. Разбить на более мелкие.
std::string Game::getFigureType(Figure *fig)
{
    bool color;
    Pawn* pPawn = dynamic_cast<Pawn*>(fig);
    if (pPawn)
    {

        color = fig->getColor();
        if(color == 0)
            return "BP";
        else
            return "WP";
    }

    Knight* pKnight = dynamic_cast<Knight*>(fig);
    if (pKnight)
    {

        color = fig->getColor();
        if (color == 0)
            return "BK";
        else
            return "WK";
    }

    Bishop* pBishop = dynamic_cast<Bishop*>(fig);
    if (pBishop)
    {

        color = fig->getColor();
        if(color == 0)
            return "BB";
        else
            return "WB";
    }

    Rook* pRook = dynamic_cast<Rook*>(fig);
    if (pRook)
    {

        color = fig->getColor();
        if(color == 0)
            return "BR" ;
        else
            return "WR";
    }

    King* pKing = dynamic_cast<King*>(fig);
    if (pKing)
    {

        color = fig->getColor();
        if(color == 0)
            return "KB";
        else
            return "KW";
    }

    Queen* pQueen = dynamic_cast<Queen*>(fig);
    if (pQueen)
    {

        color = fig->getColor();
        if(color == 0)
            return "BQ";
        else
            return "WQ" ;
    }

    if (fig == nullptr)
        return "__";

}

void Game::printBoard()
{
    //Совет Мейерса: откладывайте объявление переменных насколько это возможно.
    //Тут ты их испольуешь только в цикле. пускай они там и будут объявлены
    //если где-то пропустил этот момент, то к тем местам это тоже относится
    int i,j;

    Figure* fig = nullptr;

    if (color == 0)
        cout << "Black's move" << endl;
    else
        cout << "White's move" << endl;

    cout << "  A  B  C  D  E  F  G  H" << endl;
    for(j=0;j<8;j++){
        cout << j+1 << " ";
        for(i=0;i<8;i++){
            fig = core.getFigure(i,j);
            cout << getFigureType(fig) << " ";
        }
        cout << endl;
    }
}

void Game::menu()
{

    int menuType = 1;
    char inputValue = '3';
    string BadStr;
    //printMenu(menuType);
    while (inputValue != '0')
    {

        printMenu(menuType);
        cin >> inputValue;
        switch(inputValue)
        {

        case '1':
            menuType = 2;
            printBoard();
            printMenu(menuType);
            startGame();
            menuType = 3;
            break;

        case '0':
            break;

        default:
            cout << "Incorrect input value" << endl;
            cin.clear();
            getline(cin,BadStr);
            break;
        }
    }
    cout << "Goodbye!" << endl;
}

void Game::printMenu(int menuType) const
{
    switch (menuType) {
    case 1:
        cout << "1. Start a Chess Game " << endl;
        cout << "0. Exit " << endl;
        break;
    case 2:
        cout << "Enter the position of the figure you want to choose (letter)_(number)" << endl;
        break;
    case 3:
        cout << "1. Make a move " << endl;
        cout << "0. Exit " << endl;
        break;
    default:
        break;
    }
}

int Game::letterToInt(const char letter)
{
    int x;
    switch(letter){

    case 'a':
        x = 1; break;

    case 'b':
        x = 2; break;

    case 'c':
        x = 3; break;

    case 'd':
        x = 4; break;

    case 'e':
        x = 5; break;

    case 'f':
        x = 6; break;

    case 'g':
        x = 7; break;

    case 'h':
        x = 8; break;

    default:
        x = 0;
        break;
    }
    return x;
}

//Длинный метод. плохо читается.
//TODO разбить на более маленькие.
void Game::startGame()
{
    string BadStr;
    bool BadInput = 0;
    char letter,letter2;
    int x,y,x2,y2;
    cin >> letter;
    cin >> y;
    y = y-1;
    if (letterToInt(letter) == 0)
    {
        cout << "Incorrect input value" << endl;
        cin.clear();
        getline(cin,BadStr);
        BadInput = 1;
    }
    else
        x = letterToInt(letter)-1;

    if (BadInput == 0)
    {
        try{
            core.chooseFigure(x,y);
        }
        catch(OutOfBoardException& e){
            cout << e.what() << endl;
            BadInput = 1;
        }
        catch(EmptyCellException& e){
            cout << e.what() << endl;
            BadInput = 1;
        }
        if(BadInput == 0){
            cout << " Enter the position you want to move the selected figure" << endl;
            cin >> letter2 >> y2;
            y2-=1;
            if (letterToInt(letter2) == 0)
            {
                cout << "Incorrect input value" << endl;
                cin.clear();
                getline(cin,BadStr);
                BadInput = 1;
            }
            else
                x2 = letterToInt(letter2)-1;

            if (BadInput == 0)
            {
                try{
                    core.moveFigure(x2,y2);
                }
                catch(OutOfBoardException& e){
                    cout << e.what() << endl;
                }
                catch(SameColorFigureException& e){
                    cout << e.what() << endl;
                }
                catch(AgainstTheRulesException& e){
                    cout << e.what() << endl;
                }
            }
        }
    }
}
