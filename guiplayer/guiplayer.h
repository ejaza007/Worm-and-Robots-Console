#ifndef GUIPLAYER_H
#define GUIPLAYER_H

#include "../game_tracker/playergamehistory.h"

#include <QWidget>
#include <QString>

class menu;

QT_BEGIN_NAMESPACE
namespace Ui { class guiplayer; }
QT_END_NAMESPACE

class guiplayer : public QWidget
{
    Q_OBJECT

public:
    guiplayer(PlayerGameHistory* p, menu* m, QWidget *parent = nullptr);
    ~guiplayer();
    void sel_players();
    Player* get_sel_player() const;

private slots:

    void on_sel_player_activated(int index);

private:
    Ui::guiplayer *ui;
    menu* menu;
    PlayerGameHistory* p_g_h;
    Player* p;


};
#endif // GUIPLAYER_H
