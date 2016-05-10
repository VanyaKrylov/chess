#-------------------------------------------------
#
# Project created by QtCreator 2016-04-27T20:46:07
#
#-------------------------------------------------

QT       -= core gui

TARGET = chessEngine
TEMPLATE = lib
CONFIG += staticlib
CONFIG += console c++11

SOURCES += \
    board.cpp \
    cell.cpp \
    figure.cpp \
    API.cpp

HEADERS += \
    board.h \
    cell.h \
    figures.h \
    API.h \
    exceptions.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
