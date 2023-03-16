#include "displaytopgames.h"

using namespace std;

int partition(vector<Game*> values, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    int pivotValue = values[pivotIndex]->get_final_score();
    int i = left, j = right;
    Game* temp;
    while(i <= j) {
        while(values[i]->get_final_score() < pivotValue) {
            i++;
        }
        while(values[j]->get_final_score() > pivotValue) {
            j--;
        }
        if(i <= j) {
            temp = values[i];
            values[i] = values[j];
            values[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}

void quicksort(vector<Game*> &values, int left, int right) {
    if(left < right) {
        int pivotIndex = partition(values, left, right);
        quicksort(values, left, pivotIndex - 1);
        quicksort(values, pivotIndex, right);
    }
}

DisplayTopGames::DisplayTopGames(PlayerGameHistory* p)
{
    display_games(p);
}

void DisplayTopGames::display_games(PlayerGameHistory* p) const {
    refresh();
    clear();

    mvprintw(1, 10, "q - quit");

    //quick sort algorithm
    if (p->get_games_vector().empty()) {
        mvprintw(2, 10, "nothing to see here");
    } else {
        //check the games vector is not empty
        vector<Game*> vector_to_print;
        for (Game* game : p->get_games_vector()) {
            vector_to_print.emplace_back(game);
        }
        quicksort(vector_to_print, 0, p->get_players_vector().size()-1);
        for(int i=0; i<3; i++) {
            if (p->get_num_players() > i) {
                std::string game_name = vector_to_print[i]->get_name() + " - " + vector_to_print[i]->get_player()->get_first_name();
                if (game_name != "") {
                     mvprintw(i+2, 10, game_name.data());
                }
            }
        }
    }

    bool cont_l = true;
    do {
        // obtain character from keyboard
        int ch = getch();

        if (ch == 81 || ch == 113) { //user pressed q to quit
            cont_l = false;
        }
    } while (cont_l);

}
