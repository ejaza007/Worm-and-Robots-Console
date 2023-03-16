#include "tuirobots.h"
#include "tuiworm.h"
#include <iostream>
#include <string>
int main()
{
//TUIRobots tui;
//// tui.init();
// tui.refresh_scr();
// tui.process_input();
tuiworm tui;
tui.init();
tui.refresh_scr();
tui.process_input();

return 0;
}
