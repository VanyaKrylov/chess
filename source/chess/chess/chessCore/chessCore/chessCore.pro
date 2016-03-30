#-------------------------------------------------
#
# Project created by QtCreator 2016-03-30T23:37:01
#
#-------------------------------------------------

QT       -= core gui

TARGET = chessCore
TEMPLATE = lib
CONFIG += staticlib

SOURCES += chesscore.cpp \
    figure.cpp \
    cell.cpp

HEADERS += chesscore.h \
    figure.h \
    cell.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
