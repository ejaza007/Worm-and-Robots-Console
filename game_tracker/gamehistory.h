#ifndef GAMEHISTORY_H
#define GAMEHISTORY_H

#include <vector>
#include "game.h"

class Game;

class GameHistory
{
    //each player has a game history that is specific for that player, here we store the games of that player specifically
    std::vector<Game*> player_games;

public:
    GameHistory();
    ~GameHistory();

    int get_num_games() const;
    std::vector<Game*>& get_player_games();
};

#endif // GAMEHISTORY_H
