#ifndef DISPLAYTOPPLAYERS_H
#define DISPLAYTOPPLAYERS_H
#include <../game_tracker/playergamehistory.h>
#include <curses.h>

class DisplayTopPlayers
{
public:
    DisplayTopPlayers(PlayerGameHistory* p);

    void display_top_three(PlayerGameHistory* p) const;
};

#endif // DISPLAYTOPPLAYERS_H
