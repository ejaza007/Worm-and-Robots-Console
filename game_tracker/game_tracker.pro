TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        game.cpp \
        gamehistory.cpp \
        main.cpp \
        player.cpp \
        playergamehistory.cpp

HEADERS += \
    game.h \
    gamehistory.h \
    player.h \
    playergamehistory.h
