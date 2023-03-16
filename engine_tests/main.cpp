#include <iostream>
#include "gtest/gtest.h"
#include "../engines/robots.h"
#include "../engines/game_engine.h"
#include "../engines/worm.h"
// The fixture for testing class Foo.
class FooTest : public ::testing::Test {
protected:
    // You can remove any or all of the following functions if its body
    // is empty.
    FooTest() {
        // You can do set-up work for each test here.
        r = new Robots(12, 12);
        r->init_playspace('*');
    }
    virtual ~FooTest() {
        // You can do clean-up work that doesn’t throw exceptions here.
        delete r;
    }
    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:
    virtual void SetUp() {
        // Code here will be called immediately after the constructor (right
        // before each test).
    }
    virtual void TearDown() {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }
    // Objects declared here can be used by all tests in the test case for Foo.
    /** replace with your own **/
    Robots* r;
};
//test will ensure that the border was properly initialized
TEST(general, CREATE_BORDER) {
    Robots* r = new Robots(12, 12);
    r->init_playspace('*'); //init the playspace
    //r->print_gameboard(); //game board printed out for viewability
    //test the border was properly created
    Vector2 a;
    a.x = 0;
    a.y = 0;
    ASSERT_EQ(r->peak(a), '*');
    //test bottom left corner
    a.x = r->get_cols()-1;
    a.y = r->get_rows()-1;
    ASSERT_EQ(r->peak(a), '*');
    //test top right corner
    a.x = r->get_cols()-1;
    a.y = 0;
    ASSERT_EQ(r->peak(a), '*');
    //test right row
    for (int i=0; i<r->get_rows(); i++) {
        a.x = r->get_cols()-1;

        a.y = i;
        ASSERT_EQ(r->peak(a), '*');
    }
    //test bottom left corner
    a.x = 0;
    a.y = r->get_rows()-1;
    ASSERT_EQ(r->peak(a), '*');
    delete r;
}
//ensure that the robots are active and alive
TEST(general, ROBOT_STATE) {
    Robots* r = new Robots(12, 12);
    r->init_playspace('*');
    for(int i=0; i<r->get_num_robots(); i++) {
        ASSERT_EQ((r->get_robo_array() + i)->s, 1);
    }
    delete r; //tear down
}
//test the shortest path computation
TEST(general, ROBO_PATH_TO_PLAYER) {
    Robots* r = new Robots(12, 12);
    r->init_playspace('-'); //init the playspace
    //the robots use geo comparisons to determine the shortest path to reach the player
    //thus we can test it by giving the player specific vector2 values & seeing if the robots take the
    //shortest path
    //print out the initial setup of the game
    //get the robot positions before the computation of the alg & then compare the vectors after
    //the alg
    //these computations are dependendent on where the player is, thus get the players pos &
    //ensure the computations make sense
    Vector2 vplayer;
    vplayer = r->get_player_pos();
    printf("player pos vector: <%d, %d>\n", vplayer.x, vplayer.y);
    printf("initial robot vectors:\n");
    Vector2* roboa;
    for (int i=0; i<r->get_num_robots(); i++) {
        //robot vectors initially
        roboa = r->get_robo_array(); //pointer to the robot array
        printf("<%d, %d>", roboa[i].x, roboa[i].y);
    }
    //after we move lets see what happens to the robot positions to give us inidication of bounary
    //case that we are missing
    r->s_path_alg(); //move right
    vplayer = r->get_player_pos();
    printf("player pos vector: <%d, %d>\n", vplayer.x, vplayer.y); //shouldn't change we are testing
    //only the robots
    printf("initial robot vectors:\n");
    for (int i=0; i<r->get_num_robots(); i++) {
        //robot vectors initially
        roboa = r->get_robo_array(); //pointer to the robot array
        printf("<%d, %d>\n", roboa[i].x, roboa[i].y);
    }
    delete r;

}
//test movement methods
//for now ensure that the player moves to the correct position after moving given its initial pos on
//the gameboard
//check edge case in which the player hits the game border
TEST(general, MOVEMENT_CONTROL_ROBOT) {
    Robots* r = new Robots(12, 12);
    r->init_playspace('*');
    //test move right
    Vector2 ppos = r->get_player_pos(); //get player pos before the movement
    r->m_r();
    //ensure that the new player vector matches as well as the character is the player character at
    //that pos
    ASSERT_EQ(r->get_player_pos().x, ppos.x++);
    ASSERT_EQ(r->peak(r->get_player_pos()), '@');

    delete r;
}
//test movement of worm
TEST(general, MOVEMENT_CONTROL_WORM) {
    Worm* w = new Worm(12, 12, 'o', '@', 5);
    w->init_playspace('x');
    w->place_worm();
    w->move_right();
    ASSERT_EQ(w->get_gameboard()[6][7], '@');

    w->move_up();
    ASSERT_EQ(w->get_gameboard()[5][7], '@');
    w->move_left();
    ASSERT_EQ(w->get_gameboard()[5][6], '@');
    delete w;
    Worm* w2 = new Worm(12, 12, 'o', '@', 5);
    w2->init_playspace('x');
    w2->place_worm();
    w2->move_down();
    //ASSERT_EQ(w2->get_gameboard()[7][7], '@');
    delete w2;
}
//tests the growing of the worm
TEST(general,WORM_SIZE){
    Worm* w = new Worm(12, 12, 'o', '@', 5);
    w->init_playspace('x');
    w->place_worm();
    w->place_marker_test();

    ASSERT_EQ(w->get_worm_length(),5);
    w->move_right();
    w->move_right();
    ASSERT_EQ(w->get_worm_length(),6);
    delete w;
}
//tests if the game determines loss properly
TEST(general, WORM_LOSE){
    Worm* w = new Worm(12, 12, 'o', '@', 5);
    w->init_playspace('x');
    w->place_worm();

    //ASSERT_FALSE(w->check_lose());
    w->move_right();
    w->move_right();
    w->move_right();
    w->move_right();
    w->move_right();
    //ASSERT_TRUE(w->check_lose()); // moves right to the boundary

    delete w;
}

//TEST_F(FooTest, TESTFIXTURE) {
///** replace with your own **/
//}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
