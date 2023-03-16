QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    guitopgames.cpp \
    ../game_tracker/playergamehistory.cpp \
    ../game_tracker/player.cpp \
    ../game_tracker/game.cpp \
    ../game_tracker/gamehistory.cpp

HEADERS += \
    guitopgames.h \
    ../game_tracker/playergamehistory.h \
    ../game_tracker/player.h \
    ../game_tracker/game.h \
    ../game_tracker/gamehistory.h

FORMS += \
    guitopgames.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
