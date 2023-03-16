#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "game.h"
#include "gamehistory.h"

class Game;
class GameHistory;

class Player
{
private:
    std::string first_name;
    std::string last_name;
    std::string adr;

    Game* g; //most recent game played
    GameHistory* gh;  //tracks all games played



public:
    Player(std::string first_name, std::string last_name, std::string adr);
    ~Player();

    //get the num of games played for player in question, used within PlayerGameHistory
    int get_num_games() const;
    //get the avg score for the particular player in question
    int get_avg_score() const;
    int get_last_game_score() const;
    GameHistory* get_game_history() const;

    void play_game(Game* game);
    void set_game(Game* game);

    //getters
    std::string get_first_name() const;
    std::string get_last_name() const;
    std::string get_adr() const;
};

#endif // PLAYER_H
