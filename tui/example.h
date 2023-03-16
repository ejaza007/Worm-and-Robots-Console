#ifndef EXAMPLE_H
#define EXAMPLE_H
#include <string>
#include "screen.h"
#include "value.h"


class Example : public Screen
{
private:
        std::string state;

public:
    Example();
    ~Example();

    //method to check what character was pressed and respond appropriately
    bool process_input(Value& v) const; //returns false if none of the user pressed an unavailable key
    void draw_screen(Value& v);
};

#endif // EXAMPLE_H
