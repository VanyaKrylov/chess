#-------------------------------------------------
#
# Project created by QtCreator 2016-03-30T23:37:01
#
#-------------------------------------------------

QT       -= core gui

TARGET = chessCore
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    figure.cpp \
    cell.cpp \
    API.cpp \
    board.cpp \
    main.cpp

HEADERS += \
    cell.h \
    figures.h \
    API.h \
    board.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
