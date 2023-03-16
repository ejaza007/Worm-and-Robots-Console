#ifndef WORM_H
#define WORM_H

#include "game_engine.h"
#include <vector>

//worm uses a vector to store location of head and body
//the board then  prints characters where the body and head are
//size is incremented if the worm's head is at the location of an integer

class Worm : public Game_Engine
{
private:
    //private variables
    char m_head_char;
    char m_body_char;
    int worm_length;
    int m_row;
    int m_col;
    int score;

    std::vector<Vector2> m_body;

public:
    //public methods
    Worm (int row,int col, char body_char,char head_char, int length);
    ~Worm();
    void place_markers (int y, int x);
    void place_worm();
    void move_up();
    void move_down();
    void move_left();
    void move_right();
    bool check_lose();
    void init_playspace (char s) override; //creates the border for the world, gives lower level
    //classes ability to create own playspaces
    void place_items(char s, const Vector2& v) override;
    //movement methods
    void m_l() override;
    void m_r() override;
    void m_u() override;
    void m_d() override;
    char peak(const Vector2& v) override; //examine individual array locations
    void manip(char s, char* ptr) override; //manipulation of pieces in the array
    void win_lose(bool w_l) override;
    int get_worm_length();
    void place_marker_test();
    int marker_x_test;
    int marker_y_test;
    int marker_x;
    int marker_y;
    void create_markers();
    int randomizer;
    char marker_char;
    void random_generate();
    int get_score() const;

};
#endif // WORM_H
