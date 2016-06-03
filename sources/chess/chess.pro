TEMPLATE = subdirs

CONFIG += c++11

chessCUI.depends = chessEngine

chessGUI/chessGUI.depends = chessEngine

SUBDIRS += \
    chessEngine \
    chessGUI/chessGUI\
    Tests



