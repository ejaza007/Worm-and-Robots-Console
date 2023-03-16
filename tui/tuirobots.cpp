#include "tuirobots.h"

TUIRobots::TUIRobots()
{
    r = new Robots(12, 12);
    r->init_playspace('*');

    char display[3];



    mvprintw(1, r->get_cols()+5, "Directions:");

    mvprintw(2, r->get_cols()+6, "^");
    mvprintw(3, r->get_cols()+5, "<");
    mvprintw(3, r->get_cols()+7, ">");
    mvprintw(4, r->get_cols()+6, "v");

    mvprintw(6, r->get_cols()+5, "Commands:");

    mvprintw(7, r->get_cols()+5, "t: teleport");
    mvprintw(8, r->get_cols()+5, "q: quit");
    // print the score
    mvprintw(10, r->get_cols()+5, "Score : ");
    sprintf(display, "%d", r->get_score());
    mvprintw(10, r->get_cols()+15, display);
    for(int i=0; i<r->get_rows(); i++) {
        for (int j=0; j<r->get_cols(); j++) {
            mvprintw(i, j, &r->get_gameboard()[i][j]);
        }
    }
}

TUIRobots::~TUIRobots()
{
    delete r;
}

//draw the gameboard to the screen
void TUIRobots::draw_screen() const {
    // clear screen return cursor to (0,0)
    // temporary display string for storing the value
    // of the displayed Value object
    char display[3];

    clear();

    mvprintw(1, r->get_cols()+5, "Directions:");

    mvprintw(2, r->get_cols()+6, "^");
    mvprintw(3, r->get_cols()+5, "<");
    mvprintw(3, r->get_cols()+7, ">");
    mvprintw(4, r->get_cols()+6, "v");

    mvprintw(6, r->get_cols()+5, "Commands:");

    mvprintw(7, r->get_cols()+5, "t: teleport");
    mvprintw(8, r->get_cols()+5, "q: quit");
    // print the score
    mvprintw(10, r->get_cols()+5, "Score : ");
    sprintf(display, "%d", r->get_score());
    mvprintw(10, r->get_cols()+15, display);

    for(int i=0; i<r->get_rows(); i++) {
        for (int j=0; j<r->get_cols(); j++) {
            if (r->get_state() == lose) {
                mvprintw(12, r->get_cols()+5, "you lose");
            } else if (r->get_state() == winner) {
                mvprintw(12, r->get_cols()+5, "you win");
            }
            mvprintw(i, j, &r->get_gameboard()[i][j]);
        }
    }
}

//method to continue processing what the user presses, it is the crux of the tui functionality
void TUIRobots::process_input() {
   bool cont_l = true;
   do {
        // draw the new screen
                refresh_scr();

                // obtain character from keyboard
                int ch = get_char();

                // operate based on input character
                switch (ch) {
                case KEY_DOWN:
                    r->m_d();
                    break;
                case KEY_UP:
                    r->m_u();
                    break;
                case KEY_LEFT:
                    r->m_l();
                    break;
                case KEY_RIGHT:
                    r->m_r();
                    break;
                case 84 | 116:   //t character
                    r->teleport();
                    break;
                case 81 | 113: //q character
                    //user has quit the game, so we should get the final score
                    final_score = r->get_score();
                    cont_l = false;
                    break;
                }

                draw_screen();
   } while (cont_l);
}

int TUIRobots::get_final_score() const {
    return final_score;
}

