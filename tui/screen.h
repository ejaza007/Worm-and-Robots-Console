#ifndef SCREEN_H
#define SCREEN_H
#include <iostream>
#include <string>
#include <curses.h>
#include <../engines/game_engine.h>

class Screen
{

public:
    Screen();
    ~Screen();

    virtual void init() const;

    virtual void refresh_scr() const; //draw new screen
    virtual int get_char() const; //obtain char from keyboard

    virtual void exit() const; // cleanup the window and return control to bash
    virtual void clear_scr() const; // clear screen return cursor to (0,0)
};

#endif // SCREEN_H
