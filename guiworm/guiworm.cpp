#include "guiworm.h"
#include "ui_guiworm.h"
#include "../menu/menu.h"

guiworm::guiworm(class menu* m, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::guiworm){


    w = new Worm(12, 12,'o','@',6);
    ui->setupUi(this);
    w->init_playspace('*');

    menu = m;


    draw_board();
    w->place_worm();


}


guiworm::~guiworm()
{
    delete ui;
}


void guiworm::on_west_button_clicked() {

    w->move_left();
    draw_board();
    if (w->check_lose() == true) {
        ui->lose_label->setText("YOU LOSE");

}
}


void guiworm::on_north_button_clicked()
{
    w->move_up();
    draw_board();
    if (w->check_lose() == true) {
        ui->lose_label->setText("YOU LOSE");

}

}

void guiworm::on_south_button_clicked()
{
    w->move_down();
    draw_board();

    if (w->check_lose() == true) {
        ui->lose_label->setText("YOU LOSE");

}

}

void guiworm::on_east_button_clicked()
{
    w->move_right();
    draw_board();

    if (w->check_lose() == true) {
        ui->lose_label->setText("YOU LOSE");

}
}

void guiworm::draw_board()  {

    QString temp_board = "";

    for(int row = 0; row<w->get_rows();row++) {
        for(int col = 0; col <w->get_cols(); col++) {
            temp_board += w->get_gameboard()[row][col];
        }
        temp_board += '\n';
    }



    // Update the QTextEdit widget with the temp_board string
    ui->board_display->clear();
    ui->board_display->setText(temp_board);

     ui->score->setText(QString::fromStdString(std::to_string(w->get_score())));
}


void guiworm::on_quit_btn_clicked()
{
    Game* g = new Game(menu->active_player);
    std::string n = "Worm- " + menu->active_player->get_first_name() + " - " + std::to_string(w->get_score());
    g->set_name(n);
    //fill in the final score of the player run
    g->set_final_score(w->get_score());
    menu->active_player->set_game(g);
    menu->active_player->get_game_history()->get_player_games().emplace_back(g);
    menu->p_game_hist->get_games_vector().emplace_back(g);

    //  the window by calling close slot
    close();
    delete w;
}

