#ifndef GAME_H
#define GAME_H
#include <string>


class Player;

class Game
{
private:
    bool won;
    Player* p;  //reference player that played the game

    std::string name;
    int final_score;

public:
    Game(Player* p);
    ~Game();

    std::string get_name() const;
    void set_name(std::string n);
    int get_final_score() const;
    void set_final_score(int score);
    Player* get_player() const;
};

#endif // GAME_H
