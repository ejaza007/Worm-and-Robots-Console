#ifndef ROBOTS_H
#define ROBOTS_H
#include "game_engine.h"


//Robots use a shortest path alg. & compute 1 step toward player upon a movement of player
//thus players mem address is the target.
//Each robot does comparisons with its vector2 pos and the vector2 pos of the player as input to the shortest path alg
//shortest path alg is simple without use of graphs, it simply relys on cases given relative position.
//Each time the player moves we have error analysis to proportionally reduce the error.

enum State {running, winner, lose};

class Robots : public Game_Engine
{
private:
    Vector2 pos;
    //array of vector2 for each robot, upon init each robots vector2 must be unique
    Vector2* r_pos;
    int num_robots;
    int score;
    State state;

public:
    Robots(int r, int c);
    ~Robots();

    //general game methods
    //upon init each robots vector2 must be unique
    void init_playspace (char s) override; //creates the border for the world, gives lower level classes ability to create own playspaces
    void place_items(char s, const Vector2& v) override; //write content to the screen
    bool place_player(char s); //write player to screen
    void set_player_pos(int a, int b);
    Vector2 get_player_pos() const;
    bool del_player(); //delete player from screen
    bool place_robots(char s, char d_s); //write robot content to screen
    int get_num_robots() const;
    Vector2* get_robo_array() const;
    void del_robot(int i);
    //movement methods
    void m_l() override;
    void m_r() override;
    void m_u() override;
    void m_d() override;
    //movement methods for player to move at diagonal
    void m_45();
    void m_135();
    void m_225();
    void m_315();
    char peak(const Vector2& v) override; //examine individual array locations
    void manip(char s, char* ptr) override; //manipulation of pieces in the array
    void win_lose(bool w_l) override; //determine if player won/lost


    void s_path_alg(); //compute shortest path
    void robo_contact(int index);
    void teleport(); //generate a random valid vector2 on the board and set the players position to this vector2

    //print out the contents of gameboard array one line at a time for debugging purposes
    void print_gameboard();

    int get_rows() const;
    int get_cols() const;
    int get_score() const;
    State get_state() const;

};

#endif // ROBOTS_H
