

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <string>
#include <string.h>
#include <ctime>

// flags to enable tests for the later parts of the assignment
#define ENABLE_T1_TESTS
#define ENABLE_T2_TESTS
#define ENABLE_T3_TESTS
#define ENABLE_T4_TESTS

// include headers for classes being tested
#include "Games/randgenerator.hpp"

#include "Games/Die.hpp"
#include "Games/Dice.hpp"
#include "Games/YahtzeeInterpreter.hpp"
#include "Games/ScoreCard.hpp"
#include "Games/Player.hpp"
#include "Games/HumanPlayer.hpp"
#include "Games/AmateurBot.hpp"
#include "Games/GreedyBot.hpp"
#include "Games/MethodicalBot.hpp"
#include "Games/YahtzeeGame.hpp"


using namespace std;

int main() {

    char PlayStyle = NULL;

    //sets dice as random
	RandomGenerator::setSeed(time(nullptr));
	//has the player pick its opponent play style
	cout << "Welcome to Yahtzee! Let's Play!" << endl;
	cout << "pick your opponent type:"<< endl;
	cout << "A for Amateur"<< endl;
	cout << "G for Greedy"<< endl;
	cout << "M for methodical"<< endl;
	cout << "P for multiplayer"<< endl;
	cin >> PlayStyle;


    Player *player1 = NULL;
	Player *player2 = NULL;
	Dice dice(5);


    //assigns player type
	if (PlayStyle == 'A'||PlayStyle == 'a') {
		player1 = new HumanPlayer("player 1", dice);
		player2 = new AmateurBot("Amateurbot", dice);
    }
    else if(PlayStyle == 'G'||PlayStyle == 'g'){
        player1 = new HumanPlayer("player 1", dice);
        player2 = new GreedyBot("GreedyBot", dice);
    }
    else if(PlayStyle == 'M'||PlayStyle == 'm'){
        player1 = new HumanPlayer("player 1", dice);
        player2 = new MethodicalBot("MethodicalBot", dice);
    }
    else if(PlayStyle == 'P'||PlayStyle == 'p'){
        player1 = new HumanPlayer("player 1", dice);
        player2 = new HumanPlayer("player 2", dice);
    }



    //plays the game
	YahtzeeGame game(player1, player2, dice);
		game.play();



	return 0;
}
