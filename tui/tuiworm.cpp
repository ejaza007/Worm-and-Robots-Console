#include "tuiworm.h"
tuiworm::tuiworm()
{
    w = new Worm(24, 24, 'O', '@', 6);
    w->init_playspace('*');
    for(int i=0; i<w->get_rows(); i++) {
        for (int j=0; j<w->get_cols(); j++) {
            mvprintw(i, j, &w->get_gameboard()[i][j]);
        }
    }



}
tuiworm::~tuiworm()
{
    delete w;
}
//draw the gameboard to the screen
void tuiworm::draw_screen() const {
    // clear screen return cursor to (0,0)
    clear();
    for(int i=0; i<w->get_rows(); i++) {
        for (int j=0; j<w->get_cols(); j++) {
            mvprintw(i, j, &w->get_gameboard()[i][j]);
        }
    }
    mvprintw(10, w->get_cols()+5, "Score: ");


    mvprintw(10, w->get_cols()+10, std::to_string(w->get_score()).data());
}
//method to continue processing what the user presses, it is the crux of the tui functionality
void tuiworm::process_input() {
    bool cont_l = true;
    do {
        // draw the new screen
        refresh_scr();
        // obtain character from keyboard
        int ch = get_char();
        // operate based on input character
        switch (ch) {
        case KEY_DOWN:
            w->move_down();
            if(w->check_lose()){
                clear();
                mvprintw(12,12,"Game Over");
                final_score = w->get_score();
                cont_l = false; }
            break;
        case KEY_UP:
            w->move_up();

            if(w->check_lose()){
                clear();
                mvprintw(12,12,"Game Over");
                final_score = w->get_score();
                cont_l = false;
            }
            break;
        case KEY_LEFT:
            w->move_left();
            if(w->check_lose()){
                clear();
                mvprintw(12,12,"Game Over");
                final_score = w->get_score();
                cont_l = false;
            }
            break;
        case KEY_RIGHT:
            w->move_right();
            if(w->check_lose()){
                clear();
                mvprintw(12,12,"Game Over");
                final_score = w->get_score();
                cont_l = false;
            }
            break;
        case KEY_BACKSPACE:
            final_score = w->get_score();
            cont_l = false;
            break;
        }
        draw_screen();
    } while (cont_l);
}

int tuiworm::get_final_score() const {
    return w->get_score();
}
