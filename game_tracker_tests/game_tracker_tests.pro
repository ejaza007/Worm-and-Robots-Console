TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

### add the following lines
# if you have pthread errors, comment/uncomment the next line
LIBS += -pthread
SOURCES += ../gtest/googletest/src/gtest-all.cc
INCLUDEPATH += ../gtest \
../gtest/googletest \
../gtest/googletest/include \
../gtest/googletest/include/gtest

HEADERS += ../game_tracker/game.h \
            ../game_tracker/gamehistory.h \
            ../game_tracker/player.h \
            ../game_tracker/playergamehistory.h


SOURCES += ../game_tracker/game.cpp \
            ../game_tracker/gamehistory.cpp \
            ../game_tracker/player.cpp \
            ../game_tracker/playergamehistory.cpp



