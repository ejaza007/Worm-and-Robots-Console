#include "guirobot.h"
#include "ui_guirobot.h"
#include "../menu/menu.h"


guirobot::guirobot(class menu* m, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::guirobot)
{
    ui->setupUi(this);

    ui->board_display->setText("");
    ui->score->setText("");
    ui->w_l->setText("");

    r = new Robots(12, 12);
    r->init_playspace('*');

    menu = m;
    draw_board();
}

guirobot::~guirobot()
{
    delete r;
    delete ui;
}


void guirobot::on_west_button_clicked() {
    //move robot to the left
    r->m_l();
    draw_board();
}


void guirobot::on_north_button_clicked()
{
    r->m_u();
    draw_board();
}

void guirobot::on_south_button_clicked()
{
    r->m_d();
    draw_board();
}

void guirobot::on_east_button_clicked()
{
    r->m_r();
    draw_board();
}

void guirobot::on_quit_button_clicked()
{
    Game* g = new Game(menu->active_player);
    std::string n = "Robot- " + menu->active_player->get_first_name() + " - " + std::to_string(r->get_score());
    g->set_name(n);
    //fill in the final score of the player run
    g->set_final_score(r->get_score());
    menu->active_player->set_game(g);
    menu->active_player->get_game_history()->get_player_games().emplace_back(g);
    menu->p_game_hist->get_games_vector().emplace_back(g);
    close();
    delete r;
}

void guirobot::draw_board()  {
    //update the score if applicable
    score = r->get_score();

    QString temp_board = "";

    for(int row = 0; row<r->get_rows();row++) {
        for(int col = 0; col <r->get_cols(); col++) {
            temp_board += r->get_gameboard()[row][col];
        }
        temp_board += '\n';
    }
    ui->score->setText(QString::fromStdString(std::to_string(score)));

    if (r->get_state() == winner) {
        ui->w_l->setText("YOU WIN - Congratulations");
    } else if (r->get_state() == lose) {
        ui->w_l->setText("GAME OVER - Noble Effort");
    } else if (r->get_state() == running) {
        ui->w_l->setText("Retire all Robots");
    }



    // Update the QTextEdit widget with the temp_board string
    ui->board_display->clear();
    ui->board_display->setText(temp_board);
}



void guirobot::on_teleport_button_clicked()
{
    r->teleport();
    draw_board();
}

