#ifndef SELECTPLAYERSCREEN_H
#define SELECTPLAYERSCREEN_H

#include <curses.h>
#include <form.h>
#include <string.h>
#include <../game_tracker/playergamehistory.h>

class SelectPlayerScreen
{
private:
    PlayerGameHistory* p_game_hist;

public:
    SelectPlayerScreen(PlayerGameHistory* p);
    Player* select_player() const;
};

#endif // SELECTPLAYERSCREEN_H
