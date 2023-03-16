#include "playergamehistory.h"

PlayerGameHistory::PlayerGameHistory()
{
    //reserve some mem so that we don't have unnecessary allocation and copying because we expect more than 1 player
    players.reserve(3);
}

PlayerGameHistory::~PlayerGameHistory()
{
    //delete each player that was created upon destruction of the PlayerGameHistory
    for (Player* p : players) {
        delete p;
    }
    //delete each game that was played upon destruction
    for (Game* g : games) {
        delete g;
    }
}

int PlayerGameHistory::get_num_games_played() const {
    return games.size();
}

int PlayerGameHistory::get_num_players() const {
    return players.size();
}

int PlayerGameHistory::get_avg_games_played(Player* p) const {
    return p->get_num_games();
}

//method for getting the top game score, returns an int
//loop through each player and get an overall top game score
Game* PlayerGameHistory::get_top_game_score() const {
    //loop through each game
    if (games.empty()) {
        return nullptr;
    } else {
        Game* top_game = games[0];
        for (int i=0; i<games.size()-1; i++) {
                if (games[i+1]->get_final_score() > games[i]->get_final_score()) {
                    top_game = games[i+1];
                }
        }
        return top_game;
    }
}

int PlayerGameHistory::get_avg_game_score() const {
    if (games.empty()) {
        return 0;
    } else {
        int avg = 0;
        for (Game* game : games) {
            avg += game->get_final_score();
        }
        avg = avg / games.size();
        return avg;
    }
}

//get the avg score for a specific player
int PlayerGameHistory::get_avg_score(Player* p) const {
    return p->get_avg_score();
}

void PlayerGameHistory::add_player(Player* p) {
    //create a new player, we will be storing a pointer to that player and thus upon destruction we must loop through vector of pointers
    //and delete each player that was created
    players.emplace_back(p);
}


int PlayerGameHistory::get_final_score(Player* p) const {
    return p->get_last_game_score();
}

std::vector<Player*>& PlayerGameHistory::get_players_vector() {
    return players;
}

std::vector<Game*>& PlayerGameHistory::get_games_vector() {
    return games;
}



