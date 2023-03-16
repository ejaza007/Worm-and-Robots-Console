#ifndef GUIWORM_H
#define GUIWORM_H
#define ROWS 50
#define COLS 50
#include "../engines/worm.h"
#include <QWidget>
#include <QString>
#include <iostream>

class menu;

QT_BEGIN_NAMESPACE
namespace Ui { class guiworm; }
QT_END_NAMESPACE

class guiworm : public QWidget
{
    Q_OBJECT

public:
    guiworm(menu* m, QWidget *parent = nullptr);
    ~guiworm();
    int cols;
    int rows;


private:
    Ui::guiworm *ui;
    Worm* w;
    menu* menu;

    void draw_board();

    char board[ROWS][COLS];



private slots:

    void on_west_button_clicked();
    void on_north_button_clicked();
    void on_south_button_clicked();
    void on_east_button_clicked();
    void on_quit_btn_clicked();
};
#endif // GUIWORM_H
