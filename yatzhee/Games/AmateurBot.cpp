#include "AmateurBot.hpp"

#include <iostream>
using namespace std;

AmateurBot::AmateurBot(const std::string &name, const Dice &dice) :
		Player(name, dice) {
}

ScoreCard::Position AmateurBot::playRound() {
	//roll the dice
	dice.rollAll();
	lastCatag = posVector(round);
	lastPoints = YahtzeeInterpreter::getScoreAs(lastCatag, dice);
	//write down the data into the scorecard
	scoreData.setPointsAtPosition(lastCatag, lastPoints);

	Player::rolled(name, dice);

	round++;
	return lastCatag;
}

AmateurBot::~AmateurBot() {
}

