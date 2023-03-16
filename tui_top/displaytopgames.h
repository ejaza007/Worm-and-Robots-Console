#ifndef DISPLAYTOPGAMES_H
#define DISPLAYTOPGAMES_H

#include <curses.h>

#include <../game_tracker/playergamehistory.h>

class DisplayTopGames
{
public:
    DisplayTopGames(PlayerGameHistory* p);

    void display_games(PlayerGameHistory* p) const;


};

#endif // DISPLAYTOPGAMES_H
