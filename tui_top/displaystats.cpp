#include "displaystats.h"

DisplayStats::DisplayStats(PlayerGameHistory *p, MenuScreen* scr)
{
    print_stats(p, scr);
}


void DisplayStats::print_stats(PlayerGameHistory* p, MenuScreen* scr) const {
    refresh();
    clear();

    mvprintw(1, 10, "q - quit");

    Player* act_player = scr->get_active_player();
    std::string out;

    out = "Games played: " + std::to_string(p->get_games_vector().size());
    mvprintw(2, 10, out.data());
    out = "Number of players: " + std::to_string(p->get_num_players());
    mvprintw(3, 10, out.data());

    if (act_player != nullptr) {
        out = "Average games played: " + std::to_string(p->get_avg_games_played(act_player));
        mvprintw(4, 10, out.data());
        out = "Average score: " + std::to_string(p->get_avg_score(act_player));
        mvprintw(5, 10, out.data());
    } else {
        mvprintw(4, 10, "no active player selected");
        mvprintw(5, 10, "no active player selected");
    }

    out = "Top score: " + std::to_string(p->get_top_game_score()->get_final_score());
    mvprintw(6, 10, out.data());


    out = "Avg game score: " + std::to_string(p->get_avg_game_score());
    mvprintw(7, 10, out.data());



    bool cont_l = true;
    do {
        // obtain character from keyboard
        int ch = getch();

        if (ch == 81 || ch == 113) { //user pressed q to quit
            cont_l = false;
        }
    } while (cont_l);
}
