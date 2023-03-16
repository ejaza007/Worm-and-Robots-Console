TEMPLATE = subdirs

SUBDIRS += \
    engine_tests \
    engines \
    game_tracker \
    game_tracker_tests \
    guinewplayer \
    guiplayer \
    guirobots \
    guistats \
    guitopgames \
    guitopplayers \
    guiworm \
    menu \
    tools \
    tui \
    tui_top \
    unittest

win32:INCLUDEPATH += C:\QT\Tools\mingw1120_64\opt\include\ncursesw \
C:\QT\Tools\mingw1120_64\opt\include
win32:LIBS += C:\QT\Tools\mingw1120_64\opt\lib\libncurses.a
unix:LIBS += -lncurses
