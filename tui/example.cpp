#include "example.h"

Example::Example()
{

}


Example::~Example()
{

}

bool Example::process_input(Value& v) const {
    bool loop_en = true;
    do {
                refresh_scr();

                // obtain character from keyboard
                int ch = get_char();

                // operate based on input character
                switch (ch) {
                case KEY_DOWN:
                    v--;
                    break;
                case KEY_UP:
                    v++;
                    break;
                case KEY_LEFT:
                    v = 0;
                    break;
                case KEY_RIGHT:
                    loop_en = false;
                    break;
                }
    } while (loop_en);

    return 1;
}
void Example::draw_screen(Value& v) {
    // temporary display string for storing the value
        // of the displayed Value object.
        std::string display;

        // clear screen return cursor to (0,0)
        clear();

        // print the state of the value object
        mvprintw(2, 4, "Current Value : ");
        display = std::to_string(v.get());
        mvprintw(2, 21, display.c_str());

        // print the instructions for manipulating the Value object
        mvprintw(5, 4, "Up Arrow    : increments value");
        mvprintw(6, 4, "Down Arrow  : decrements value");
        mvprintw(7, 4, "Left Arrow  : resets value to zero");
        mvprintw(8, 4, "Right Arrow : exits program");
}
