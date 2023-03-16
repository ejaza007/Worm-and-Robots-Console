#ifndef TUIROBOTS_H
#define TUIROBOTS_H
#include "screen.h"
#include "../engines/robots.h"


class TUIRobots : public Screen
{
protected:
    Robots* r; //robot game instance
    int final_score;

public:
    TUIRobots();
    ~TUIRobots();
    void draw_screen() const;
    void process_input();
    int get_final_score() const;

};

#endif // TUIROBOTS_H
