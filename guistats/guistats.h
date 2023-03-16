#ifndef GUISTATS_H
#define GUISTATS_H

#include <QWidget>
#include "../game_tracker/playergamehistory.h"

class menu;

QT_BEGIN_NAMESPACE
namespace Ui { class guistats; }
QT_END_NAMESPACE

class guistats : public QWidget
{
    Q_OBJECT

public:
    guistats(PlayerGameHistory* p, menu* m, QWidget *parent = nullptr);
    ~guistats();

    void display_stats(PlayerGameHistory* p, menu* m);

private slots:
    void on_pushButton_clicked();

private:
    Ui::guistats *ui;
};
#endif // GUISTATS_H
