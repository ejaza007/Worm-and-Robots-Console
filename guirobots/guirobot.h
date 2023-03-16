#ifndef GUIROBOT_H
#define GUIROBOT_H

#include "../engines/robots.h"

#include <QWidget>
#include <QString>

class menu;


QT_BEGIN_NAMESPACE
namespace Ui { class guirobot; }
QT_END_NAMESPACE

class guirobot : public QWidget
{
    Q_OBJECT

public:
    explicit guirobot(menu* m, QWidget *parent = nullptr);
    ~guirobot();



private slots:

    void on_west_button_clicked();
    void on_north_button_clicked();
    void on_south_button_clicked();
    void on_east_button_clicked();

    void on_quit_button_clicked();

    void on_teleport_button_clicked();



private:
    Ui::guirobot *ui;
    Robots* r;
    menu* menu;
    void draw_board();
    //keep track of the score of the game locally
    int score;



};
#endif // GUIROBOT_H
