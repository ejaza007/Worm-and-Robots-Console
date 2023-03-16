#include "menuscreen.h"
#include <iostream>

#include <../game_tracker/playergamehistory.h>

int main()
{
    PlayerGameHistory* h = new PlayerGameHistory();
    MenuScreen* scr = new MenuScreen(h);

}
