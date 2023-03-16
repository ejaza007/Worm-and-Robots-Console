#ifndef PLAYERGAMEHISTORY_H
#define PLAYERGAMEHISTORY_H
#include "player.h"
#include "game.h"
#include <vector>

class PlayerGameHistory
{
private:
    std::vector<Player*> players;
    std::vector<Game*> games;

public:
    PlayerGameHistory();
    ~PlayerGameHistory();

    //stats
    int get_num_games_played() const;
    int get_num_players() const;
    int get_avg_games_played(Player* p) const;
    Game* get_top_game_score() const;
    int get_avg_game_score() const;
    int get_avg_score(Player* p) const;

    //upon creation of a player we can assign that player to a new game or have the option of creating a new game for that player in
    //the case of the default constructor case
    std::vector<Player*>& get_players_vector();
    std::vector<Game*>& get_games_vector();
    void add_player(Player* p);
    int get_final_score(Player* p) const;
};

#endif // PLAYERGAMEHISTORY_H
