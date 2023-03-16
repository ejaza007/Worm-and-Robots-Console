#ifndef CREATEPLAYERSCREEN_H
#define CREATEPLAYERSCREEN_H

#include <curses.h>
#include <form.h>
#include <../game_tracker/playergamehistory.h>


class CreatePlayerScreen
{
private:
    PlayerGameHistory* p_game_hist;
public:
    CreatePlayerScreen(PlayerGameHistory* p);
    ~CreatePlayerScreen();


    void create_player_form() const;

};

#endif // CREATEPLAYERSCREEN_H
