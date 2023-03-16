TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

win32:INCLUDEPATH += C:\QT\Tools\mingw1120_64\opt\include     \
                     C:\QT\Tools\mingw1120_64\opt\include\ncursesw

win32:LIBS += C:\QT\Tools\mingw1120_64\opt\lib\libformw.a     \
              C:\QT\Tools\mingw1120_64\opt\lib\libncurses.a


unix:LIBS += -lncurses -lform

SOURCES += \
        createplayerscreen.cpp \
        displaystats.cpp \
        displaytopgames.cpp \
        displaytopplayers.cpp \
        main.cpp \
        menuscreen.cpp \
        playrobots.cpp \
        playworm.cpp \
        selectplayerscreen.cpp \
        ../game_tracker/playergamehistory.cpp \
        ../game_tracker/player.cpp \
        ../game_tracker/game.cpp \
        ../game_tracker/gamehistory.cpp \
        ../tui/screen.cpp \
        ../tui/tuirobots.cpp \
        ../tui/tuiworm.cpp \
        ../engines/game_engine.cpp \
        ../engines/robots.cpp \
        ../engines/worm.cpp




HEADERS += \
    createplayerscreen.h \
    displaystats.h \
    displaytopgames.h \
    displaytopplayers.h \
    menuscreen.h \
    playrobots.h \
    playworm.h \
    selectplayerscreen.h \
    ../game_tracker/playergamehistory.h \
    ../game_tracker/player.h \
    ../game_tracker/gamehistory.h \
    ../tui/screen.h \
    ../tui/tuirobots.h \
    ../tui/tuiworm.h \
    ../engines/game_engine.h \
    ../engines/robots.h \
    ../engines/worm.h
