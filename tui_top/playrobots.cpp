#include "playrobots.h"

PlayRobots::PlayRobots()
{
    tui = new TUIRobots();
    tui->refresh_scr();
    tui->process_input();
}

PlayRobots::~PlayRobots()
{
   delete tui;
}

int PlayRobots::get_score() const {
    return tui->get_final_score();
}
