#include "player.h"

Player::Player(std::string first_name, std::string last_name, std::string adr)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->adr = adr;

    gh = new GameHistory();

}

Player::~Player()
{
    delete gh;
}

int Player::get_num_games() const {
    return gh->get_num_games();
}

int Player::get_avg_score() const {
    //loop through the games stored in game history and calculate avg score for each of those games
    int num = 0;
    int avg = 0;
    //add each final score
    for (Game* g : gh->get_player_games()) {
        num = num + g->get_final_score();
    }
    //calculate avg
    if (num > 0) {
        avg = num / gh->get_player_games().size();
    }
    return avg;
}

int Player::get_last_game_score() const {
    return g->get_final_score();
}

void Player::play_game(Game* game) {
     g = game;
}

void Player::set_game(Game* game) {
    g = game;
}

std::string Player::get_first_name() const {
    return first_name;
}
std::string Player::get_last_name() const {
    return last_name;
}
std::string Player::get_adr() const {
    return adr;
}

GameHistory* Player::get_game_history() const {
    return gh;
}
