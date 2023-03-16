#include "guitopgames.h"
#include "ui_guitopgames.h"

using namespace std;

guitopgames::guitopgames(PlayerGameHistory* p, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::guitopgames)
{
    ui->setupUi(this);
    ui->l1->setText("");
    ui->l2->setText("");
    ui->l3->setText("");

    display_games(p);
}

guitopgames::~guitopgames()
{
    delete ui;
}
int partition(vector<Game*> values, int left, int right);
void quicksort(vector<Game*> &values, int left, int right);
int partition(vector<Game*> values, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    int pivotValue = values[pivotIndex]->get_final_score();
    int i = left, j = right;
    Game* temp;
    while(i <= j) {
        while(values[i]->get_final_score() < pivotValue) {
            i++;
        }
        while(values[j]->get_final_score() > pivotValue) {
            j--;
        }
        if(i <= j) {
            temp = values[i];
            values[i] = values[j];
            values[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}

void quicksort(vector<Game*> &values, int left, int right) {
    if(left < right) {
        int pivotIndex = partition(values, left, right);
        quicksort(values, left, pivotIndex - 1);
        quicksort(values, pivotIndex, right);
    }
}

void guitopgames::display_games(PlayerGameHistory* p) {

    if (p->get_players_vector().empty()) {

    } else {
        //quick sort algorithm
        std::vector<Game*> vector_to_print;
        for (Game* game : p->get_games_vector()) {
            vector_to_print.emplace_back(game);
        }
        quicksort(vector_to_print, 0, p->get_players_vector().size()-1);


        if (vector_to_print.size() >= 1) {
            std::string g_name_0 = vector_to_print[0]->get_name();
            if (g_name_0 != "") {
                ui->l1->setText(QString::fromStdString(g_name_0));
            }
        }

        if (vector_to_print.size() >= 2) {
            std::string g_name_1 = vector_to_print[1]->get_name();
            if (g_name_1 != "") {
                ui->l2->setText(QString::fromStdString(g_name_1));
            }
        }

        if (vector_to_print.size() >= 3) {
            std::string g_name_2 = vector_to_print[2]->get_name();
            if (g_name_2 != "") {
                ui->l3->setText(QString::fromStdString(g_name_2));
            }
        }
    }
}


void guitopgames::on_pushButton_clicked()
{
    close();
}

