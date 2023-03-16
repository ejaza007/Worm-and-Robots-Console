QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    menu.cpp \
    ../engines/game_engine.cpp \
    ../engines/robots.cpp \
    ../engines/worm.cpp \
    ../guirobots/guirobot.cpp \
    ../guiworm/guiworm.cpp \
    ../guistats/guistats.cpp \
    ../guiplayer/guiplayer.cpp \
    ../guinewplayer/guinewplayer.cpp \
    ../guitopgames/guitopgames.cpp \
    ../guitopplayers/guitopplayers.cpp \
    ../game_tracker/playergamehistory.cpp \
    ../game_tracker/player.cpp \
    ../game_tracker/gamehistory.cpp \
    ../game_tracker/game.cpp


HEADERS += \
    menu.h \
    ../engines/game_engine.h \
    ../engines/robots.h \
    ../engines/worm.h \
    ../guirobots/guirobot.h \
    ../guiworm/guiworm.h \
    ../guistats/guistats.h \
    ../guiplayer/guiplayer.h \
    ../guinewplayer/guinewplayer.h \
    ../guitopgames/guitopgames.h \
    ../guitopplayers/guitopplayers.h \
    ../game_tracker/playergamehistory.h \
    ../game_tracker/player.h \
    ../game_tracker/gamehistory.h \
    ../game_tracker/game.h

FORMS += \
    menu.ui \
    ../guirobots/guirobot.ui \
    ../guiworm/guiworm.ui \
    ../guistats/guistats.ui \
    ../guiplayer/guiplayer.ui \
    ../guinewplayer/guinewplayer.ui \
    ../guitopgames/guitopgames.ui \
    ../guitopplayers/guitopplayers.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
