#include "displaytopplayers.h"
#include <algorithm>

using namespace std;

DisplayTopPlayers::DisplayTopPlayers(PlayerGameHistory* p)
{
    display_top_three(p);
}

int partition(vector<Player*> values, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    int pivotValue = values[pivotIndex]->get_avg_score();
    int i = left, j = right;
    Player* temp;
    while(i <= j) {
        while(values[i]->get_avg_score() < pivotValue) {
            i++;
        }
        while(values[j]->get_avg_score() > pivotValue) {
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

void quicksort(vector<Player*> &values, int left, int right) {
    if(left < right) {
        int pivotIndex = partition(values, left, right);
        quicksort(values, left, pivotIndex - 1);
        quicksort(values, pivotIndex, right);
    }
}


void DisplayTopPlayers::display_top_three(PlayerGameHistory* p) const {
    refresh();
    clear();

    mvprintw(1, 10, "q - quit");


    if (p->get_players_vector().empty()) {
        mvprintw(2, 10, "nothing to see here");
    } else {
        //quick sort algorithm
        std::vector<Player*> vector_to_print;
        for (Player* player : p->get_players_vector()) {
            vector_to_print.emplace_back(player);
        }
        quicksort(vector_to_print, 0, p->get_players_vector().size()-1);

        for(int i=0; i<3; i++) {
            if (p->get_num_players() > i) {
                std::string p_name = vector_to_print[i]->get_first_name();
                if (p_name != "") {
                     mvprintw(i+2, 10, p_name.data());
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
