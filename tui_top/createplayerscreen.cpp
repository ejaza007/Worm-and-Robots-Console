#include "createplayerscreen.h"
#include "../game_tracker/player.h"

CreatePlayerScreen::CreatePlayerScreen(PlayerGameHistory* p)
{
    p_game_hist = p;
    create_player_form();
}

CreatePlayerScreen::~CreatePlayerScreen()
{

}


//this method will create the form for player, filling the player fields with form text
void CreatePlayerScreen::create_player_form() const {
    refresh();


    //player has first name, last name and address
    FIELD *field[4];
    FORM  *my_form;

    field[0] = new_field(1, 10, 4, 19, 0, 0);
    field[1] = new_field(1, 10, 6, 19, 0, 0);
    field[2] = new_field(1, 10, 6, 19, 0, 0);

    field[3] = NULL;

    bool cont_l = true;

    // Print a line for the option.
    set_field_back(field[0], A_UNDERLINE);
    set_field_back(field[1], A_UNDERLINE);
    set_field_back(field[2], A_UNDERLINE);

    //  Don't go to next field when this field is filled up.
    field_opts_off(field[0], O_AUTOSKIP);
    field_opts_off(field[1], O_AUTOSKIP);
    field_opts_off(field[2], O_AUTOSKIP);


    // Create the form and post it.
    my_form = new_form(field);
    post_form(my_form);
    // build the form
    refresh();

    // display labels
    mvprintw(4, 10, "First: ");
    mvprintw(6, 10, "Last: ");
    mvprintw(7, 10, "Address: ");

    // place the cursor
    move(4, 19);

    // perform last refresh
    refresh();


    do {
            // obtain character from keyboard
            int ch = getch();

            switch(ch) {
            case KEY_DOWN:

                // go to next field
                form_driver(my_form, REQ_NEXT_FIELD);

                // Go to the end of the present buffer
                // and leave nicely at the last character
                form_driver(my_form, REQ_END_LINE);

                break;

            case KEY_UP:

                // go to previous field
                form_driver(my_form, REQ_PREV_FIELD);

                // Go to the end of the present buffer
                // and leave nicely at the last character
                form_driver(my_form, REQ_END_LINE);

                break;

            case KEY_LEFT:

                // exit from loop
                cont_l = false;

                // stores the buffer on the field it is located
                form_driver(my_form, REQ_END_LINE);
                break;

            default:
                // If this is a normal character, print it.
                form_driver(my_form, ch);
                break;
            }

        } while (cont_l);


        // Un post form and free the memory
        unpost_form(my_form);
        free_form(my_form);

        // store contents of fields before they are +++freed
        std::string field0_value = field_buffer(field[0],0);
        std::string field1_value = field_buffer(field[1],0);
        std::string field2_value = field_buffer(field[2],0);

        //create a new player object
        Player* player = new Player(field0_value, field1_value, field2_value);
        //add it to the vector of players, now we have a new player within the PlayerGameHistory object
        p_game_hist->add_player(player);
}
