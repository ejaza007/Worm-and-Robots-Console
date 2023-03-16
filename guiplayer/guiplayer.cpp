#include "guiplayer.h"
#include "ui_guiplayer.h"
#include "../menu/menu.h"
#include <iostream>
#include <ostream>



guiplayer::guiplayer(PlayerGameHistory* p, class menu* m ,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::guiplayer)
{
    ui->setupUi(this);

    p_g_h = p;
    menu = m;
    sel_players();
}

guiplayer::~guiplayer()
{
    delete ui;
}

//we need to use buttons to display players
//that can be selected
void guiplayer::sel_players() {
    //create buttons for each player
    //with the ability to select a player

    //display all existing players that have
    //been created and allow for selection of a particular one
    if (!p_g_h->get_players_vector().empty()) {
        for (int i=0; i<p_g_h->get_players_vector().size(); i++) {
            std::string adr = p_g_h->get_players_vector()[i]->get_first_name();
            QString qstr = QString::fromStdString(adr);
            ui->sel_player->addItem(qstr);
        }
    }
    //now we have a combo box of items, we need to be able to select one of these and set an active player
    //at the parent class level



}


Player* guiplayer::get_sel_player() const {
    return p;
}


void guiplayer::on_sel_player_activated(int index)
{
    //returns the index within the combo box that was changed, and since we added them in order we
    //can simply set the player at that index to the active player
        //we have a valid index selected
        //so we can simply set the active player to the player at that vector index
        menu->active_player = p_g_h->get_players_vector()[index];
        menu->display_active_player();
        //close the gui
        this->close();
}

