#ifndef DISPLAYSTATS_H
#define DISPLAYSTATS_H

#include "menuscreen.h"
#include <curses.h>

#include <../game_tracker/playergamehistory.h>

class DisplayStats
{
public:
    DisplayStats(PlayerGameHistory* p, MenuScreen* m);

    void print_stats(PlayerGameHistory* p, MenuScreen* m) const;
};

#endif // DISPLAYSTATS_H
