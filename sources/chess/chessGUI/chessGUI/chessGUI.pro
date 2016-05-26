#-------------------------------------------------
#
# Project created by QtCreator 2016-05-26T09:51:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chessGUI
TEMPLATE = app


SOURCES += main.cpp\
        startMenu.cpp \
    mainwindow.cpp

HEADERS  += startMenu.h \
    mainwindow.h

FORMS    += startMenu.ui

RESOURCES += \
    resources.qrc
