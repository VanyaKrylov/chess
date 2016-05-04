TEMPLATE = subdirs

CONFIG += c++11

chessCUI.depends = chessEngine

SUBDIRS += \
    chessEngine \
    chessCUI
