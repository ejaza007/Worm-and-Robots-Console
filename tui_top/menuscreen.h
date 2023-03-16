#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include <curses.h>
#include <form.h>
#include <../game_tracker/playergamehistory.h>
#include <playworm.h>
#include <playrobots.h>
#include <../tui/screen.h>

class MenuScreen : public Screen
{
protected:
    PlayerGameHistory* p_game_hist;
    Player* active_player;

public:
    MenuScreen(PlayerGameHistory* p);
    ~MenuScreen();

    void gen_field();
    void exit_prgm() const;
    void set_active_player(Player* p);
    Player* get_active_player() const;
    void write_dir() const;
};

#endif // MENUSCREEN_H
