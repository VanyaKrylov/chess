#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"startMenu.h"
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QApplication>
#include <QDesktopWidget>
#include "board.h"

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
    Board *b;

signals:

public slots:
    void startButtonPressed();

};

#endif // MAINWINDOW_H
