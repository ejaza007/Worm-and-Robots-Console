#ifndef TUIWORM_H
#define TUIWORM_H
#include "screen.h"
#include "../engines/worm.h"

class tuiworm : public Screen
{
protected:
    Worm* w; //robot game instance
    int final_score;

public:
    tuiworm();
    ~tuiworm();
    void draw_screen() const;
    void process_input();
    int get_final_score() const;
    std::string charscore;
};
#endif // TUIROBOTS_H
