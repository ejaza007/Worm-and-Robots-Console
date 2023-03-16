#ifndef GUINEWPLAYER_H
#define GUINEWPLAYER_H

#include <QWidget>
#include <QString>

#include <../game_tracker/playergamehistory.h>

QT_BEGIN_NAMESPACE
namespace Ui { class guinewplayer; }
QT_END_NAMESPACE

class guinewplayer : public QWidget
{
    Q_OBJECT

public:
    explicit guinewplayer(PlayerGameHistory* p, QWidget *parent = nullptr);
    ~guinewplayer();

private slots:
    void on_first_name_textEdited(const QString &arg1);

    void on_last_name_textEdited(const QString &arg1);

    void on_adr_textEdited(const QString &arg1);

    void on_ok_btn_clicked();

private:
    Ui::guinewplayer *ui;
    QWidget* par;
    PlayerGameHistory* p_g_h;
    std::string first;
    std::string last;
    std::string adr;
};
#endif // GUINEWPLAYER_H
