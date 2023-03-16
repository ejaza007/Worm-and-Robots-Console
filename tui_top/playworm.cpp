#include "playworm.h"

PlayWorm::PlayWorm()
{
    tui = new tuiworm();
    tui->refresh_scr();
    tui->process_input();
}

PlayWorm::~PlayWorm()
{

}

int PlayWorm::get_score() const {
    return tui->get_final_score();
}

tuiworm* PlayWorm::get_tui() const {
    return tui;
}
