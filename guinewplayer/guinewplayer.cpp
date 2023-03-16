#include "guinewplayer.h"
#include "ui_guinewplayer.h"

guinewplayer::guinewplayer(PlayerGameHistory* p, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::guinewplayer)
{
    ui->setupUi(this);
    par = parent;

    p_g_h = p;

}

guinewplayer::~guinewplayer()
{
    delete ui;
}

void guinewplayer::on_first_name_textEdited(const QString &arg1)
{
    first = arg1.toStdString();
}


void guinewplayer::on_last_name_textEdited(const QString &arg1)
{
    last = arg1.toStdString();
}

void guinewplayer::on_adr_textEdited(const QString &arg1)
{
    adr = arg1.toStdString();
}

void guinewplayer::on_ok_btn_clicked()
{
    Player* player = new Player(first, last, adr);
    p_g_h->add_player(player);
    //go back to the home screen
    this->close();
}

