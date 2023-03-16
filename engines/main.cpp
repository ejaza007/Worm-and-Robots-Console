#include "robots.h"
#include "worm.h"
#include <iostream>

using namespace std;

int main()
{
//    //print the gameboard and run commands to address bug involving game ending
//    //lets init the playspace & then print out the players position & the position of each of our robots
//    Robots* r = new Robots(12, 12);
//    r->init_playspace('-'); //init the playspace
//    r->print_gameboard(); //print initial state of the gameboard
//    Vector2 vplayer;
//    vplayer = r->get_player_pos();
//    printf("player pos vector: <%d, %d>\n", vplayer.x, vplayer.y);
//     printf("initial robot vectors:\n");
//    Vector2* roboa;
//    for (int i=0; i<r->get_num_robots(); i++) {
//        //robot vectors initially
//        roboa = r->get_robo_array(); //pointer to the robot array
//        printf("<%d, %d>", roboa[i].x, roboa[i].y);
//    }
//    //after we move lets see what happens to the robot positions to give us inidication of bounary case that we are missing
//    r->m_r(); //move right
//    r->print_gameboard();
//    vplayer = r->get_player_pos();
//    printf("player pos vector: <%d, %d>\n", vplayer.x, vplayer.y);
//     printf("initial robot vectors:\n");
//    for (int i=0; i<r->get_num_robots(); i++) {
//        //robot vectors initially
//        roboa = r->get_robo_array(); //pointer to the robot array
//        printf("<%d, %d>\n", roboa[i].x, roboa[i].y);
//    }
//    r->m_r(); //move right
//    r->print_gameboard();
//    vplayer = r->get_player_pos();
//    printf("player pos vector: <%d, %d>\n", vplayer.x, vplayer.y);
//     printf("initial robot vectors:\n");
//    for (int i=0; i<r->get_num_robots(); i++) {
//        //robot vectors initially
//        roboa = r->get_robo_array(); //pointer to the robot array
//        printf("<%d, %d>\n", roboa[i].x, roboa[i].y);
//    }
//    r->teleport();//test teleport functionality
//    r->print_gameboard();
//    r->m_d(); //move down
//    r->print_gameboard();
//    vplayer = r->get_player_pos();
//    printf("player pos vector: <%d, %d>\n", vplayer.x, vplayer.y);
//     printf("initial robot vectors:\n");
//    for (int i=0; i<r->get_num_robots(); i++) {
//        //robot vectors initially
//        roboa = r->get_robo_array(); //pointer to the robot array
//        printf("<%d, %d>\n", roboa[i].x, roboa[i].y);
//    }
//    r->m_d(); //move down
//    r->print_gameboard();
//    vplayer = r->get_player_pos();
//    printf("player pos vector: <%d, %d>\n", vplayer.x, vplayer.y);
//     printf("initial robot vectors:\n");
//    for (int i=0; i<r->get_num_robots(); i++) {
//        //robot vectors initially
//        roboa = r->get_robo_array(); //pointer to the robot array
//        printf("<%d, %d>\n", roboa[i].x, roboa[i].y);
//    }
//    r->m_l(); //move down
//    r->print_gameboard();
//    vplayer = r->get_player_pos();
//    printf("player pos vector: <%d, %d>\n", vplayer.x, vplayer.y);
//     printf("initial robot vectors:\n");
//    for (int i=0; i<r->get_num_robots(); i++) {
//        //robot vectors initially
//        roboa = r->get_robo_array(); //pointer to the robot array
//        printf("<%d, %d>\n", roboa[i].x, roboa[i].y);
//    }
//    r->m_d(); //move down
//    r->print_gameboard();
//    vplayer = r->get_player_pos();
//    printf("player pos vector: <%d, %d>\n", vplayer.x, vplayer.y);
//     printf("initial robot vectors:\n");
//    for (int i=0; i<r->get_num_robots(); i++) {
//        //robot vectors initially
//        roboa = r->get_robo_array(); //pointer to the robot array
//        printf("<%d, %d>\n", roboa[i].x, roboa[i].y);
//    }

//    delete r;
}
