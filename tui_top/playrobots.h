#ifndef PLAYROBOTS_H
#define PLAYROBOTS_H

#include "../tui/tuirobots.h"


class PlayRobots
{
private:
    TUIRobots* tui;
public:
    PlayRobots();
    ~PlayRobots();

    int get_score() const;
};

#endif // PLAYROBOTS_H
