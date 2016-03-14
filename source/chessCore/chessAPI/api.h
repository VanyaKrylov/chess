#ifndef API_H
#define API_H


class API
{
public:

    API();
    void SelectFigure(int x, int y); ///Выбор фигуры, которой игрок хочет сделать свой ход
    int MoveFigure(int x0, int y0, int x, int y); ///Ход выбранной игрокой фигурой на указанную игроком клетку
    void SetGameSettings(int ColorOfFigures, bool Oponent); ///Установка параметров игры
    void StartGame();///Запуск игры
    void StartNewGame();///Запуск новой игры
    void LoadGame();///Запуск ранее сохранённой игры
    void SaveGame();///Сохранение игры на текущем моменте

};

#endif // API_H
