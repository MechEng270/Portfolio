#include "YahtzeeGame.hpp"
#include "ScoreCard.hpp"

#include <stdlib.h>
#include <iostream>
using namespace std;

YahtzeeGame::YahtzeeGame(Player *player1, Player *player2, const Dice &dice) {
	this->player1 = player1;
	this->player2 = player2;
	this->dice = dice;
}

void YahtzeeGame::printStatusSoFar(Player *player,
		ScoreCard::Position positionPlayed) const {
	cout << player->getName() << " played "
			<< ScoreCard::getPositionName(positionPlayed) << " for "
			<< player->getPointsLastRound() << " points. Total score so far: "
			<< player->getPointsTotal() << "." << endl;
}

void YahtzeeGame::play() {
	srand(0);

	for (int round = 1; round <= 13; round++) {
		cout << endl << "============================================";
		cout << endl << "  Round " << round;
		cout << endl << "============================================" << endl;



		ScoreCard::Position player1Position = player1->playRound();
		cout << endl;
		ScoreCard::Position player2Position = player2->playRound();
		cout << endl;


		printStatusSoFar(player1, player1Position);
		printStatusSoFar(player2, player2Position);
	}

	cout << endl << "*********************************************";
	cout << endl << "  Final Results ";
	cout << endl << "*********************************************" << endl;
	cout << player1->getName() << "'s final score: "
			<< player1->getPointsTotal() << endl;
	cout << player2->getName() << "'s final score: "
			<< player2->getPointsTotal() << endl << endl;

	if (player1->getPointsTotal() > player2->getPointsTotal()) {
		cout << player1->getName() << " wins!" << endl;
	} else if (player2->getPointsTotal() > player1->getPointsTotal()) {
		cout << player2->getName() << " wins!" << endl;
	} else {
		cout << "It's a draw!" << endl;
	}
}

YahtzeeGame::~YahtzeeGame() {
}

