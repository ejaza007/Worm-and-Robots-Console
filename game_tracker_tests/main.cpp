#include <iostream>
#include "gtest/gtest.h"
#include "../game_tracker/game.h"
#include "../game_tracker/gamehistory.h"
#include "../game_tracker/player.h"
#include "../game_tracker/playergamehistory.h"
 //The fixture for testing class Foo.
class FooTest : public ::testing::Test {
protected:
    // You can remove any or all of the following functions if its body
    // is empty.
    FooTest() {
        // You can do set-up work for each test here.
    }
    virtual ~FooTest() {
        // You can do clean-up work that doesn’t throw exceptions here.
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
};

//create a playergame history object and add a bunch of players to the vector of players
//TEST(general, PLAYERGAMEHISTORY) {
//    PlayerGameHistory* pgh = new PlayerGameHistory();

//    //ASSERT_EQ();
//}

//test the num games method
TEST(general, GET_NUM_GAMES) {
    PlayerGameHistory* pgh = new PlayerGameHistory();
    //create fictional player
    Player* p1 = new Player("liam", "stew", "2sfd3");
    pgh->add_player(p1);
    //have the player play a fictional game
    Game* g1 = new Game(p1);
    //set the players last game pointer
    p1->set_game(g1);
    pgh->get_games_vector().emplace_back(g1);

    //the game played above was played by p1 in this scenario

    //1 game was played
    ASSERT_EQ(pgh->get_num_games_played(), 1);
    //lets say the same player plays another game
    Game* g2 = new Game(p1);
    //last game is reset
    p1->set_game(g2);
    //now we should have 2 games played
    pgh->get_games_vector().emplace_back(g2);
    ASSERT_EQ(pgh->get_num_games_played(), 2);

    delete pgh;
}

//test the num players method
TEST(general, GET_NUM_PlAYERS) {
    PlayerGameHistory* pgh = new PlayerGameHistory();
    //create fictional player

    for (int i=0; i<50; i++) {
        //create 50 players and add them
        Player* p = new Player("liam", "stew", "2sfd3");
        pgh->add_player(p);
    }

    //we should have 50 players
    ASSERT_EQ(pgh->get_num_players(), 50);

    delete pgh;
}

//test the average games played method
TEST(general, GET_AVG_GAMES_PLAYED) {
    PlayerGameHistory* pgh = new PlayerGameHistory();
    //create fictional player
    Player* p1 = new Player("liam", "stew", "2sfd3");
    Player* p2 = new Player("sergei", "ivranov", "sdf");
    //now for that specific player we want to get the games played
    pgh->add_player(p1);
    pgh->add_player(p2);
    //have the player play a fictional game
    Game* g1 = new Game(p1);
    Game* g2 = new Game(p1);
    Game* g3 = new Game(p2);
    //set the players last game pointer
    p1->set_game(g1);
    p2->set_game(g3);
    //lets say that player in particular played game 1, 2 and 3
    p1->get_game_history()->get_player_games().emplace_back(g1);
    p1->get_game_history()->get_player_games().emplace_back(g2);
    p2->get_game_history()->get_player_games().emplace_back(g3);
    //if we call get_avg games played we expect 2 for player 1 and 1 for player 2

    ASSERT_EQ(pgh->get_avg_games_played(p1), 2);
    ASSERT_EQ(pgh->get_avg_games_played(p2), 1);

    delete pgh;
}


//test the top game score method
TEST(general, GET_TOP_SCORE) {
    PlayerGameHistory* pgh = new PlayerGameHistory();
    //create 2 fictional players
    Player* p1 = new Player("liam", "stew", "2sfd3");
    Player* p2 = new Player("sergei", "ivranov", "sdf");
    //now for that specific player we want to get the games played
    pgh->add_player(p1);
    pgh->add_player(p2);
    //have the player play a fictional game
    Game* g1 = new Game(p1);
    Game* g2 = new Game(p2);
    //lets say they had a high score of 4
    g1->set_final_score(4);
    g2->set_final_score(2);
    pgh->get_games_vector().emplace_back(g1);
    pgh->get_games_vector().emplace_back(g2);


    ASSERT_EQ(pgh->get_top_game_score(), g1);

    delete pgh;
}

//test the avg game score method
TEST(general, GET_AVG_GAME_SCORE) {
    PlayerGameHistory* pgh = new PlayerGameHistory();
    //create 2 fictional players
    Player* p1 = new Player("liam", "stew", "2sfd3");
    Player* p2 = new Player("sergei", "ivranov", "sdf");
    //now for that specific player we want to get the games played
    pgh->add_player(p1);
    pgh->add_player(p2);
    //have the player play a fictional game
    Game* g1 = new Game(p1);
    Game* g2 = new Game(p2);
    //lets say they had a high score of 4
    g1->set_final_score(4);
    g2->set_final_score(2);
    //we should see an avg game score of 3
    pgh->get_games_vector().emplace_back(g1);
    pgh->get_games_vector().emplace_back(g2);


    ASSERT_EQ(pgh->get_avg_game_score(), 3);

    delete pgh;
}

//test the avg score method
TEST(general, GET_AVG_SCORE) {
    PlayerGameHistory* pgh = new PlayerGameHistory();
    //create 2 fictional players
    Player* p1 = new Player("liam", "stew", "2sfd3");
    Player* p2 = new Player("sergei", "ivranov", "sdf");
    //now for that specific player we want to get the games played
    pgh->add_player(p1);
    pgh->add_player(p2);
    //have the player play a fictional game
    Game* g1 = new Game(p1);
    Game* g2 = new Game(p2);
    //lets say they had a high score of 4
    g1->set_final_score(4);
    g2->set_final_score(2);
    p1->get_game_history()->get_player_games().emplace_back(g1);
    p2->get_game_history()->get_player_games().emplace_back(g2);
    //we should see an avg game score of 3
    pgh->get_games_vector().emplace_back(g1);
    pgh->get_games_vector().emplace_back(g2);




    //avg score calculation for a specific player
    ASSERT_EQ(pgh->get_avg_score(p1), 4);

    delete pgh;
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
