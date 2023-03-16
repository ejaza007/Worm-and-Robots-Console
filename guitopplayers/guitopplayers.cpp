#include "guitopplayers.h"
#include "ui_guitopplayers.h"

using namespace std;

guitopplayers::guitopplayers( PlayerGameHistory* p, QWidget *parent)
    : QWidget(parent)
    ,ui(new Ui::guitopplayers)
{
    ui->setupUi(this);
    ui->l1->setText("");
    ui->l2->setText("");
    ui->l3->setText("");


    display_top_three(p);
}

guitopplayers::~guitopplayers()
{
    delete ui;
}

int partition(vector<Player*> values, int left, int right);
void quicksort(vector<Player*> &values, int left, int right);

int partition(vector<Player*> values, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    int pivotValue = values[pivotIndex]->get_avg_score();
    int i = left, j = right;
    Player* temp;
    while(i <= j) {
        while(values[i]->get_avg_score() < pivotValue) {
            i++;
        }
        while(values[j]->get_avg_score() > pivotValue) {
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

void quicksort(vector<Player*> &values, int left, int right) {
    if(left < right) {
        int pivotIndex = partition(values, left, right);
        quicksort(values, left, pivotIndex - 1);
        quicksort(values, pivotIndex, right);
    }
}


void guitopplayers::display_top_three(PlayerGameHistory* p) {

    if (p->get_players_vector().empty()) {

    } else {
        //quick sort algorithm
        std::vector<Player*> vector_to_print;
        for (Player* player : p->get_players_vector()) {
            vector_to_print.emplace_back(player);
        }
        quicksort(vector_to_print, 0, p->get_players_vector().size()-1);


        if (vector_to_print.size() >= 1) {
            std::string p_name_0 = vector_to_print[0]->get_first_name();
            if (p_name_0 != "") {
                ui->l1->setText(QString::fromStdString(p_name_0));
            }
        }

        if (vector_to_print.size() >= 2) {
            std::string p_name_1 = vector_to_print[1]->get_first_name();
            if (p_name_1 != "") {
                ui->l2->setText(QString::fromStdString(p_name_1));
            }
        }

        if (vector_to_print.size() >= 3) {
            std::string p_name_2 = vector_to_print[2]->get_first_name();
            if (p_name_2 != "") {
                ui->l3->setText(QString::fromStdString(p_name_2));
            }
        }
    }
}


void guitopplayers::on_pushButton_clicked()
{
    close();
}

