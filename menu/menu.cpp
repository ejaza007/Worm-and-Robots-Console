#include "menu.h"
#include "ui_menu.h"


menu::menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::menu)
{
    ui->setupUi(this);

    ui->current_player->setText("no active player selected");
    active_player = nullptr;

    p_game_hist = new PlayerGameHistory();
}

menu::~menu()
{
    delete ui;
}



void menu::on_worm_btn_clicked()
{
    if (active_player != nullptr) {
            w = new guiworm(this, this);
            w->show();
    }
}

void menu::on_robot_button_clicked()
{
    if (active_player != nullptr) {
           r = new guirobot(this, this);
           r->show();
    }
}

void menu::on_actionNew_Player_triggered()
{
    new_p = new guinewplayer(p_game_hist, this);
    new_p->show();
}


void menu::on_actionSelect_Existing_triggered()
{
    if (p_game_hist->get_players_vector().size() > 0) {
        sel_p = new guiplayer(p_game_hist,this, this);
        sel_p->show();
    }
}


void menu::on_actionTop_Three_Players_triggered()
{
    top_p = new guitopplayers(p_game_hist, this);
    top_p->show();
}


void menu::on_actionTop_3_Games_triggered()
{
    top_g = new guitopgames(p_game_hist,this);
    top_g->show();
}

void menu::on_actionCalculated_Stats_triggered()
{
    //if there are no games played we cannot display any statistics
    if (active_player != nullptr && p_game_hist->get_games_vector().size() != 0) {
        stats = new guistats(p_game_hist,this,this);
        stats->show();
    }
}


void menu::on_actionon_quit_triggered()
{
    this->close();
}

void menu::display_active_player() {
    //display the current active player
    if (active_player != nullptr && active_player->get_first_name() != "") {
        std::string name = active_player->get_first_name();
        QString qstr = QString::fromStdString(name);
        ui->current_player->clear();
        ui->current_player->setText(qstr);
    }
}

void menu::set_active_player(Player* p) {
        active_player = p;
}
