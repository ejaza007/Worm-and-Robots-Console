#ifndef PLAYWORM_H
#define PLAYWORM_H

#include "../tui/tuiworm.h"

class PlayWorm
{
private:
    tuiworm* tui;

public:
    PlayWorm();
    ~PlayWorm();

    int get_score() const;
    //for debugging
    tuiworm* get_tui() const;
};

#endif // PLAYWORM_H
