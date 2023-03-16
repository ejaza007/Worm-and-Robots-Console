#ifndef GUITOPPLAYERS_H
#define GUITOPPLAYERS_H

#include <QWidget>
#include "../game_tracker/playergamehistory.h"

QT_BEGIN_NAMESPACE
namespace Ui { class guitopplayers; }
QT_END_NAMESPACE

class guitopplayers : public QWidget
{
    Q_OBJECT

public:
    guitopplayers(PlayerGameHistory* p, QWidget *parent = nullptr);
    ~guitopplayers();

    void display_top_three(PlayerGameHistory* p);

private slots:
    void on_pushButton_clicked();

private:
    Ui::guitopplayers *ui;
};
#endif // GUITOPPLAYERS_H
