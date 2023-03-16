#include "gamehistory.h"

//stores the games played for a specific player in game played order
//references each game played by the specific player
GameHistory::GameHistory()
{

}

GameHistory::~GameHistory()
{

}

int GameHistory::get_num_games() const {
    return player_games.size();
}

std::vector<Game*>& GameHistory::get_player_games() {
    return player_games;
}
