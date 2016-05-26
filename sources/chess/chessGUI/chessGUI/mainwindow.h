#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"startMenu.h"
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

private:
    QStackedWidget *stack;
    QPushButton *yes;
    QPushButton *no;
    Dialog *startMenu;

signals:

public slots:
    void exitButtonPressed();
};

#endif // MAINWINDOW_H
