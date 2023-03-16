#ifndef MENU_H
#define MENU_H

#include "../game_tracker/playergamehistory.h"
#include "../game_tracker/player.h"

#include "../guirobots/guirobot.h"
#include "../guiplayer/guiplayer.h"
#include "../guiworm/guiworm.h"
#include "../guistats/guistats.h"
#include "../guinewplayer/guinewplayer.h"
#include "../guitopgames/guitopgames.h"
#include "../guitopplayers/guitopplayers.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class menu; }
QT_END_NAMESPACE

class menu : public QMainWindow
{
    Q_OBJECT

public:
    menu(QWidget *parent = nullptr);
    ~menu();

    void display_active_player();
    void set_active_player(Player* p);
    void exit_prgm() const;
    void write_dir() const;

private slots:

    void on_worm_btn_clicked();


    void on_robot_button_clicked();

    void on_actionNew_Player_triggered();

    void on_actionSelect_Existing_triggered();

    void on_actionTop_Three_Players_triggered();

    void on_actionTop_3_Games_triggered();

    void on_actionCalculated_Stats_triggered();

    void on_actionon_quit_triggered();


private:
    Ui::menu *ui;
    guirobot* r;
    guiworm* w;

    guiplayer* sel_p;
    guistats* stats;
    guitopplayers* top_p;
    guitopgames* top_g;
    guinewplayer* new_p;

public:
    Player* active_player;
    PlayerGameHistory* p_game_hist;
};
#endif // MENU_H
