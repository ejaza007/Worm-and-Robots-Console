#include "selectplayerscreen.h"
#include <iostream>
#include <ostream>
#include <string>

SelectPlayerScreen::SelectPlayerScreen(PlayerGameHistory* p)
{
    p_game_hist = p;
}


Player* SelectPlayerScreen::select_player() const {
    clear();
    refresh();
    //display all existing players in a way similar to main menu screen
    //allow for selection of a player, all games played will be attributed to this player

    //print out all players with index's if the user enters the index than that player will be chosen
    // display directions

    for (int i=0; i<p_game_hist->get_players_vector().size(); i++) {
        std::string output = std::to_string(i) + " - " + p_game_hist->get_players_vector()[i]->get_first_name();
        mvprintw(i+1, 10, output.data());
    }
    mvprintw(p_game_hist->get_players_vector().size()+3, 10, "q - quit");

    bool cont_l = true;
    do {
        // obtain character from keyboard
        int ch = getch();
        //valid player selected
        if (ch > 47 && ch < 48 + p_game_hist->get_players_vector().size()) {
            Player* p = p_game_hist->get_players_vector().at(ch-48);
            if (p != nullptr) {
                return p;
            }
        } else if (ch == 81 || ch == 113) cont_l = false;
    } while (cont_l);
}
