#include "game.h"

Game::Game(Player* player)
{
    p = player;
}

Game::~Game()
{
}

std::string Game::get_name() const {
    return name;
}

int Game::get_final_score() const {
    return final_score;
}

Player* Game::get_player() const {
    return p;
}

void Game::set_final_score(int score) {
    final_score = score;
}

void Game::set_name(std::string n) {
    name = n;
}



