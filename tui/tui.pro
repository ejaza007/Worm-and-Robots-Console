TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

win32:INCLUDEPATH += C:\QT\Tools\mingw1120_64\opt\include\ncursesw \
                     C:\QT\Tools\mingw1120_64\opt\include

win32:LIBS += C:\QT\Tools\mingw1120_64\opt\lib\libncurses.a

unix:LIBS += -lncurses

SOURCES += \
        example.cpp \
        main.cpp \
        screen.cpp \
        tuirobots.cpp \
        tuiworm.cpp \
        value.cpp \
        ../engines/game_engine.cpp \
        ../engines/robots.cpp \
        ../engines/worm.cpp


HEADERS += \
    example.h \
    screen.h \
    tuirobots.h \
    tuiworm.h \
    value.h \
    ../engines/game_engine.h \
    ../engines/robots.h \
    ../engines/worm.h
