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
    API.cpp \
    boardLogic.cpp \
    mycell.cpp \
    figures.cpp

HEADERS += \
    figures.h \
    API.h \
    exceptions.h \
    boardLogic.h \
    mycell.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
