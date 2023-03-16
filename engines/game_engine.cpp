#include "game_engine.h"

Game_Engine::Game_Engine()
{
}

Game_Engine::~Game_Engine()
{
}

bool Game_Engine::check_null() {
    if (gameboard == nullptr) {
        return 0;
    }
    return 1;
}

//peak a gameboard position for the character at that position
char Game_Engine::peak(const Vector2& v) {
    return gameboard[v.y][v.x];
}

//for debugging purposes
void Game_Engine::print_gameboard() {
    for(int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
             std::cout << gameboard[i][j];
        }
        std::cout << "\n";
    }
}

char** Game_Engine::get_gameboard() const {
    return gameboard;
}

int Game_Engine::get_rows() const {
    return rows;
}
int Game_Engine::get_cols() const {
    return columns;
}


