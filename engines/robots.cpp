#include "robots.h"
#include "game_engine.h"


//constructor of the robots game
//initially we need to first write the border to the gameboard & then init the player pos and the robot positions
//then we call the write method to populate the gameboard with the characters at the proper vector2 positions within the 2-d array
Robots::Robots(int r, int c)
{
    rows = r;
    columns = c;
    score = 0;
    //memory block of size rows
    gameboard = new char*[rows];

    for (int i=0; i<rows; i++) {
        gameboard[i] = new char[columns];
    }

    for(int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
             gameboard[i][j] = ' ';
        }
    }
    state = running;
}

Robots::~Robots() {
    for (int i=0; i<rows; i++) {
        delete[] gameboard[i]; //delete inner
    }
    delete[] gameboard; //delete the outer array

    delete r_pos;
}

//init array of robot vector2's, each must be unique
//we take in the size of the playspace as params
void Robots::init_playspace(char s)  {
    //write in the border of the playspace
    for (int i=0; i<rows; i++) {
        gameboard[i][0] = s;
        gameboard[i][columns-1] = s;
    }
    for (int i=0; i<columns; i++) {
        gameboard[0][i] = s;
        gameboard[rows-1][i] = s;
    }
    //init the initial player pos within the playspace
    //we need to ensure that initially the player does not spawn into the same position as a robot
    pos.x = 1 + (std::rand() % (columns - 2)); //use COLS - 2 because we have a border fill of 1
    pos.y = 1 + (std::rand() % (rows - 2));

    //initialize player state as alive
    pos.s = 1;

    //given the number of elements in the playspace generate a proportional number of robots
    num_robots = (columns * rows)/30; //the 30 is a placeholder for now, in the future a random number will be generated
    r_pos = new Vector2[num_robots];
    for (int i=0; i<num_robots; i++) { //loop through array generating random vector2s on each pass
        int r_posx = 1 + (std::rand() % (columns - 2));
        int r_posy = 1 + (std::rand() % (rows - 2));
        //give each robot a random x & y pos
        r_pos[i].x = r_posx;
        r_pos[i].y = r_posy;
        //all robots should initially be alive
        r_pos[i].s = 1;
    }

    //call write method to write the robots & player to the gameboard array initially
    place_robots('+', '*');
    place_player('@');
}

//each time a player moves it updates the Vector2 for player
//loop through the array of robot vector2s and calculate error for each one
//compute new r_xpos and r_ypos to reduce error & set the char
//at the old pos to ' ' & replace new array pos with '+'

//this method will be called write after the user invokes a movement method with the arrow keys
void Robots::s_path_alg() {
    //loop through robot positions & calculate error for each one
    //call write to update gameboard array with new vector pos, robots that have collided should not be updated
    int win_count = 0; //see if all the robots states are zero by incrementing each, if that is the case they are all dead so we do nothing

    for (int i=0; i<num_robots; i++) {
         int e_x = pos.x - r_pos[i].x; //error in the x
         int e_y =  pos.y - r_pos[i].y;

         //we don't want to move dead robots so for each robot check its vector2 state to see if it is dead
         if (r_pos[i].s == 0) {
             //do nothing
         } else {
             //shortest path alg:
             if (e_x > 0 && e_y > 0 && e_x == e_y) {
                 del_robot(i); //the robot is moving thus we erase its previous char
                 r_pos[i].x++;
                 r_pos[i].y++;
                 robo_contact(i); //see if the current robot in the iteration has hit the player or any other robots
             } else if (e_x > 0 && std::abs(e_x) > std::abs(e_y)) {
                 del_robot(i);
                 r_pos[i].x++;
                 robo_contact(i);
             } else if (e_y > 0 && std::abs(e_y) > std::abs(e_x)) {
                 del_robot(i);
                 r_pos[i].y++;
                 robo_contact(i);
             } else if (e_x < 0 && e_y < 0 && e_x == e_y) {
                 del_robot(i);
                 r_pos[i].x--;
                 r_pos[i].y--;
                 robo_contact(i);
             } else if (e_x > 0 && e_y < 0 && std::abs(e_x) == std::abs(e_y)) {
                 del_robot(i);
                 r_pos[i].x++;
                 r_pos[i].y--;
                 robo_contact(i);
             } else if (e_x < 0 && e_y > 0 && std::abs(e_x) == std::abs(e_y)) {
                 del_robot(i);
                 r_pos[i].x--;
                 r_pos[i].y++;
                 robo_contact(i);
             } else if (e_x < 0 && std::abs(e_x) > std::abs(e_y)) {
                 del_robot(i);
                 r_pos[i].x--;
                 robo_contact(i);
             } else if (e_y < 0 && std::abs(e_y) > std::abs(e_x)) {
                 del_robot(i);
                 r_pos[i].y--;
                 robo_contact(i);
             }
         }
         win_count += r_pos[i].s;
    }

    if (win_count == 0) win_lose(1);
}

//write each robots position into the gameboard 2d array
//in the case that the robot was destroyed we write in a * at that pos
bool Robots::place_robots(char s, char d_s) {
    //loop through the robot vector2 array and at each pos write in a char s, in example '+' was used, unless the state is 0 meaning destroyed
    try {
        for (int i=0; i<num_robots; i++) {
            int r_xpos = r_pos[i].x;
            int r_ypos = r_pos[i].y;

            if (r_pos[i].s == 0) { //the robot we want to write was destroyed so we write a '*'
                gameboard[r_ypos][r_xpos] = d_s;
            } else { //write a '+' if robot is still alive
                gameboard[r_ypos][r_xpos] = s;
            }
        }
        return 1;
    } catch (const std::exception &e) {
        return 0;
    }
}

//method for placing items in into the world, for now it takes a character to place and a vector pos
void Robots::place_items(char s, const Vector2& v) {
    gameboard[v.y][v.x] = s;
}

//manipulate the contents of a specific mem address in array using a pointer and the value to change to
void Robots::manip(char s, char* ptr) {
    if (ptr != nullptr) {
        *ptr = s;
    }
}

//method for replacing former robot characters with ' ' to remove symbol so that
//robots actually simulate movement
void Robots::del_robot(int i) {
            //if the robot is moving than we must delete it before we move
            //get the x & y pos of the robot to move
            int r_xpos = r_pos[i].x;
            int r_ypos = r_pos[i].y;

            //set the gameboard at the old x & y pos to ' ' because we will be moving
            gameboard[r_ypos][r_xpos] = ' ';
}

//to erase the former players character at the prev position they were located, called each time before a player moves
bool Robots::del_player() {
        try {
            gameboard[pos.y][pos.x] = ' ';
            return 1;
        } catch (const std::exception &e) {
            return 0;
        }
}

//write the players position into the gameboard
bool Robots::place_player(char s) {
    try {
        gameboard[pos.y][pos.x] = s;
        return 1;
    } catch (const std::exception &e) {
        return 0;
    }

}

//method for determining if their is contact between 2 robots with each other or with the player
void Robots::robo_contact(int index) {
    //right after we move robots we check in the case that we have collided with another robot (death) or we have hit the player (lose)
    if (r_pos[index].s != 0) {
        if (r_pos[index].x == pos.x && r_pos[index].y == pos.y) {
            //you lose
            win_lose(0);
            //the player is dead so we set his state to 0
            pos.s = 0;
            del_player(); //and we delete him from the world
        }
        for (int i=0; i<num_robots; i++) {
            //if the current robots position is equal to any of the other robots positions then we set its state to
            //zero to indicate that the robot has died, this is done for each robot as it moves & thus it will kill any robots that
            //share poisitions between them
            //however we need to ensure that the current robot is not iterate over
            if (r_pos[index].x == r_pos[i].x && r_pos[index].y == r_pos[i].y && r_pos[i].s != 0) {
                //the current robot has indeed hit another one upon moving & thus we set it's state to dead
                //check to ensure we we are not comparing to the current robot, we can do this using a pointer comparison
                //we are treating the index in the array as the characterization for the robot & thus we can compare it to itself
                Vector2* ptr;
                ptr = &r_pos[index];
                if (ptr != &r_pos[i]) {
                    //we have a case where the vectors match & we are not looking at the same robot
                    //thus we set the state to zero of the current and the one we hit
                     r_pos[index].s = 0;
                     r_pos[i].s = 0;
                     score += 2;
                }
            }
        }
    }
}

//method for moving player, it is called in the case that the user asserts left arrow key or h
void Robots::m_l() {
    if (state == running) {
        if (pos.x <= 1) {
            //you lose, you collided with the border
            win_lose(0);
        } else if (pos.s != 0 && state == running) {
            //player moved, therefore the robots must compute their path alg & then everything must be drawn to the screen
            del_player(); //the previous indices where player were written to gameboard we replace with ' '
            pos.x--;
            s_path_alg(); //robots will move toward player but before they too will erase former chars in the gameboard
            place_player('@');
            place_robots('+', '*');
        }
    }
}

void Robots::m_r() {
    if (state == running) {
        if (pos.x >= columns - 2) {
            //you lose, you collided with the border
            win_lose(0);
        } else if (pos.s != 0 && state == running) {
            del_player();
            pos.x++;
            s_path_alg();
            place_player('@');
            place_robots('+', '*');
        }
    }
}
void Robots::m_u() {
    if (state == running) {
        if (pos.y <= 1) {
            //you lose, you collided with the border
            win_lose(0);
        } else if (pos.s != 0 && state == running) {
            del_player();
            pos.y--;
            s_path_alg();
            place_player('@');
            place_robots('+', '*');
        }
    }
}
void Robots::m_d() {
    if (state == running) {
        if (pos.y >= rows - 2) {
            //you lose, you collided with the border
            win_lose(0);
        } else if (pos.s != 0 && state == running) {
            del_player();
            pos.y++;
            s_path_alg();
            place_player('@');
            place_robots('+', '*');
        }
    }
}

//method called during a critical action during game that may cause
//user to win or lose the game
void Robots::win_lose(bool w_l) {
    if (w_l == 0) {
        state = lose;
    } else {
        state = winner;
    }
}

//method for moving the player out of a corner
//at higher level the io will use this method when the user
//invokes teleport command
//generate a random valid vector2 on the board and set the
//players position to this vector2
void Robots::teleport() {
    //since we have moved the player, its previous unteleported char
    //must be set to ' '
    //all robots come back to life if teleport is enabled
    //we must teleport to a safe position, therefore we can create an algoritm that gives us a max separation between
    //all the robots postions & the new teleported position

    if (state == running) {
        if (pos.s != 0) { //if the player is still alive, he can teleport
            del_player();
            pos.x = 1 + (std::rand() % (columns - 2));
            pos.y = 1 + (std::rand() % (rows - 2));
        }
        place_player('@');
        place_robots('+', '*');
    }
}

//peak a gameboard position for the character at that position
char Robots::peak(const Vector2& v) {
    return gameboard[v.y][v.x];
}

//for debugging purposes
void Robots::print_gameboard() {
    for(int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
             std::cout << gameboard[i][j];
        }
        std::cout << "\n";
    }
}

int Robots::get_num_robots() const {
    return num_robots;
}

Vector2* Robots::get_robo_array() const {
    return r_pos;
}

void Robots::set_player_pos(int a, int b) {
    pos.x = a;
    pos.y = b;
}

Vector2 Robots::get_player_pos() const {
    return pos;
}

int Robots::get_rows() const {
    return rows;
}
int Robots::get_cols() const {
    return columns;
}

int Robots::get_score() const {
    return score;
}

State Robots::get_state() const {
    return state;
}









