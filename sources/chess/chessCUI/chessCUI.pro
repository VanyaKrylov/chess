TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    game.cpp


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../chessEngine/release/ -lchessEngine
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../chessEngine/debug/ -lchessEngine
else:unix: LIBS += -L$$OUT_PWD/../chessEngine/ -lchessEngine

INCLUDEPATH += $$PWD/../chessEngine
DEPENDPATH += $$PWD/../chessEngine

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../chessEngine/release/libchessEngine.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../chessEngine/debug/libchessEngine.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../chessEngine/release/chessEngine.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../chessEngine/debug/chessEngine.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../chessEngine/libchessEngine.a

HEADERS += \
    game.h
