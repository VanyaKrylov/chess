#-------------------------------------------------
#
# Project created by QtCreator 2016-04-27T20:46:07
#
#-------------------------------------------------

QT       -= core gui

TARGET = chessEngine
TEMPLATE = lib
CONFIG += staticlib

SOURCES += chessengine.cpp \
    API.cpp \
    board.cpp \
    cell.cpp \
    figure.cpp

HEADERS += chessengine.h \
    API.h \
    board.h \
    cell.h \
    figures.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
