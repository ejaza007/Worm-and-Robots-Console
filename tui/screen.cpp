#include "screen.h"

Screen::Screen()
{
}

Screen::~Screen()
{
}

//pass in a bool to control whether we can hide the cursor from view
void Screen::init() const {
        initscr();
        // disables line buffering and erase/kill character-processing
        // (interrupt and flow control characters are unaffected),
        // making characters typed by the  user  immediately
        // available to the program
        // hide the cursor from view (comment this line out for debugging)
        curs_set(0);
        cbreak();

        // control whether characters  typed  by  the user  are echoed
        // by getch as they are typed
        noecho();

        // the user can press a function key (such as an arrow key) and
        // getch returns a single value representing the  function  key,
        // as in KEY_LEFT
        keypad(stdscr, TRUE);
}

void Screen::refresh_scr() const {
    refresh();
}

int Screen::get_char() const {
    return getch();
}

void Screen::exit() const {
    endwin();
}

void Screen::clear_scr() const {
    clear();
}
