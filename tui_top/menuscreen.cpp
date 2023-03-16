#include "menuscreen.h"
#include "createplayerscreen.h"
#include "displaystats.h"
#include "displaytopplayers.h"
#include "selectplayerscreen.h"
#include "displaytopgames.h"


MenuScreen::MenuScreen(PlayerGameHistory* p)
{
    init();

    this->p_game_hist = p;
    this->active_player = nullptr;

    gen_field();
}
MenuScreen::~MenuScreen()
{

}



void MenuScreen::gen_field() {
    write_dir();

    // perform last refresh
    refresh();

    bool cont_l = true;

    do {
        // obtain character from keyboard
        int ch = getch();

        switch(ch) {

        case 65 | 97: { //a character
            //create a player screen that will be used to enter form info on a new player
            CreatePlayerScreen* plyr_screen = new CreatePlayerScreen(p_game_hist);
            delete plyr_screen;
            //in the case the user presses a they want to create a a new player, so we transfer to that screen
            write_dir();

            break;
        }
        case 66 | 98: { //b character
            //select an existing player
            SelectPlayerScreen* scr = new SelectPlayerScreen(p_game_hist);
            Player* p = scr->select_player();
            set_active_player(p);
            delete scr;
            write_dir();
            break;
        }
        case 67 | 99: { //c character
            //display top three players based on avg game score
            DisplayTopPlayers* t_scr = new DisplayTopPlayers(p_game_hist);
            delete t_scr;
            write_dir();
            break;
        }
        case 68 | 100: { //d character
            //display the top three games played based on final game score
            DisplayTopGames* g_scr = new DisplayTopGames(p_game_hist);
            delete g_scr;
            write_dir();
            break;
        }
        case 69 | 101: { //e character
            DisplayStats* stats = new DisplayStats(p_game_hist, this);
            delete stats;
            write_dir();
            break;
        }
        case 70 | 102: { //f character
            //ensure that an active player has been selected
            if (active_player != nullptr) {
                PlayRobots* p_r = new PlayRobots();
                //create a new game that corresponds to current run
                Game* g = new Game(active_player);
                g->set_name("Robot run");
                g->set_final_score(p_r->get_score());

                active_player->set_game(g);
                //create a
                active_player->get_game_history()->get_player_games().emplace_back(g);
                p_game_hist->get_games_vector().emplace_back(g);
               //fill in the final score of the player run


                delete p_r;
            }
            write_dir();
            break;
        }
        case 71 | 103: { //g character
            //ensure that an active player has been selected
            if (active_player != nullptr) {
                PlayWorm* p_w = new PlayWorm();
                //create a new game that corresponds to current run
                Game* g = new Game(active_player);
                g->set_name("Worm run");
                active_player->set_game(g);
                active_player->get_game_history()->get_player_games().emplace_back(g);
                p_game_hist->get_games_vector().emplace_back(g);
                //fill in the final score of the player run
                g->set_final_score(p_w->get_score());

                delete p_w;
            }
            write_dir();
            break;
        }
        case 81 | 113: { //q character
            cont_l = false;
            break;
        }
        }

    } while (cont_l);

    // exit ncurses environment
    exit();
}

void MenuScreen::write_dir() const {
    clear();
    refresh_scr();
    // display directions
 if (active_player != nullptr) {
       if (active_player->get_first_name() != "") {
            std::string act_plyr_name = active_player->get_first_name();
           std::string output = "Current Player: " + act_plyr_name;
            mvprintw(3, 10, output.data());
      }
 } else {
        mvprintw(3, 10, "Current Player: No Player Selected");
   }


    mvprintw(4, 10, "a. Create a New Player");
    mvprintw(5, 10, "b. Select an Existing Player");
    mvprintw(9, 5, "c. Display Top Three Players");
    mvprintw(10, 5, "d. Display Top Three Games Played");
    mvprintw(11, 5, "e. Display Calculated Statistics");
    mvprintw( 12, 5, "f. Play Robots");
    mvprintw(13, 5, "g. Play Worm");
    mvprintw(14, 5, "q. Exit Program");
}

void MenuScreen::set_active_player(Player* p) {
    active_player = p;
}

Player* MenuScreen::get_active_player() const {
    return active_player;
}

void MenuScreen::exit_prgm() const {
    exit();
}
