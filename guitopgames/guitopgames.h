#ifndef GUITOPGAMES_H
#define GUITOPGAMES_H

#include "../game_tracker/playergamehistory.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {class guitopgames; }
QT_END_NAMESPACE

class guitopgames : public QWidget
{
    Q_OBJECT

public:
    guitopgames(PlayerGameHistory* p, QWidget *parent = nullptr);
    ~guitopgames();

    void display_games(PlayerGameHistory* p);

private slots:
    void on_pushButton_clicked();

private:
    Ui::guitopgames *ui;
};
#endif // GUITOPGAMES_H
