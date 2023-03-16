TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        game_engine.cpp \
        main.cpp \
        robots.cpp \
        worm.cpp

HEADERS += \
    game_engine.h \
    robots.h \
    worm.h
