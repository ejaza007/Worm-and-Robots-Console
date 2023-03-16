#include "guistats.h"
#include "ui_guistats.h"
#include "../menu/menu.h"

guistats::guistats(PlayerGameHistory* p, class menu* m, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::guistats)
{
    ui->setupUi(this);

    display_stats(p, m);
}

guistats::~guistats()
{
    delete ui;
}


void guistats::display_stats(PlayerGameHistory* p, menu* m) {

    if (p->get_players_vector().empty()) {

    } else {
        Player* act_player = m->active_player;
        std::string out;

        out = "Games played: " + std::to_string(p->get_games_vector().size());
        ui->l1->setText(QString::fromStdString(out));
        out = "Number of players: " + std::to_string(p->get_num_players());
        ui->l2->setText(QString::fromStdString(out));
        if (act_player != nullptr) {
            out = "Average games played: " + std::to_string(p->get_avg_games_played(act_player));
            ui->l3->setText(QString::fromStdString(out));
            out = "Average score: " + std::to_string(p->get_avg_score(act_player));
            ui->l4->setText(QString::fromStdString(out));
        }

        out = "Top score: " + std::to_string(p->get_top_game_score()->get_final_score());
        ui->l5->setText(QString::fromStdString(out));

        out = "Avg game score: " + std::to_string(p->get_avg_game_score());
        ui->l6->setText(QString::fromStdString(out));
    }
}



void guistats::on_pushButton_clicked()
{
    close();
}

