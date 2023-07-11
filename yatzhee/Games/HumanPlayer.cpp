#include "HumanPlayer.hpp"
#include <iostream>
#include <string>
using namespace std;

HumanPlayer::HumanPlayer(const std::string &name, const Dice &dice) :
		Player(name, dice) {
	// TODO implement
}

ScoreCard::Position HumanPlayer::playRound() {
	dice.rollAll();
	Player::rolled2(name, dice, 0);

	char holds[6];

	//rolls dice and holds those the players says to hold
	for (int n = 0; n < 2; n++) {

		cout << "Choose which dice to (H)old or (R)oll:";
		cin >> holds;

		Dice rollnt = Dice();

		for (int i = 0; i < 5; i++) {

			if (holds[i] == 'H'||holds[i] == 'h') {
				rollnt.addDie(dice.getDie(i));
			}
		}
		//rolls the rest
		dice.rollAllBut(rollnt);
		Player::rolled2(name, dice, n + 1);
	}

	//give optional catagories ot selct from
	cout << "Possible positions available:" << endl;
	//lists all availalbe catagories and points from them
	for (int i = 0; i < 13; i++) {
		if (!scoreData.isPositionSet(posVector(i))) {
			int score = YahtzeeInterpreter::getScoreAs(posVector(i), dice);
			cout << (i + 1) << " for " << posString(i) << " (worth " << score
					<< " points)" << endl;
		}
	}

	//decision picking
	int dec = -1;

	cout << endl << "Select from one of the above corresponding positions for ";
	cout << "[" << dice.getDieValue(0) << ", " << dice.getDieValue(1) << ", "
			<< dice.getDieValue(2) << ", " << dice.getDieValue(3) << ", "
			<< dice.getDieValue(4) << "]: ";

	cin >> dec;

	lastCatag = posVector(dec - 1);
	lastPoints = YahtzeeInterpreter::getScoreAs(lastCatag, dice);
	scoreData.setPointsAtPosition(lastCatag, lastPoints);

	return lastCatag;

}

HumanPlayer::~HumanPlayer() {
}

