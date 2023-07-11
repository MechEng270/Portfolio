#include "GreedyBot.hpp"
#include <iostream>
using namespace std;

GreedyBot::GreedyBot(const std::string &name, const Dice &dice) :
		Player(name, dice) {
}

ScoreCard::Position GreedyBot::playRound() {

	lastCatag = ScoreCard::NOT_SET;
	int highestCat = 0;

	dice.rollAll();
	Player::rolled(name, dice);

	for (int n = 0; n < 2; n++) {

		int num = dice.getHighestMultiple().getDieValue(0);

		Dice rollnt = Dice();

		//hold dies which have the most common dies
		for (int i = 0; i < 5; i++) {
			num = dice.getHighestMultiple().getDieValue(0);

			if (dice.getDieValue(i) == (num)) {
				rollnt.addDie(dice.getDie(i));
			}
		}
		//if yatzee then full sends it
		if (YahtzeeInterpreter::getScoreAs(ScoreCard::YAHTZEE, dice) == 50
				&& !scoreData.isPositionSet(ScoreCard::YAHTZEE)) {

			lastCatag = ScoreCard::YAHTZEE;
			lastPoints = YahtzeeInterpreter::getScoreAs(lastCatag, dice);
			scoreData.setPointsAtPosition(lastCatag, lastPoints);
			return lastCatag;
		}

		//rolls the rest
		Player::holds(dice, rollnt);
		dice.rollAllBut(rollnt);
		Player::rolled(name, dice);
	}

	bool search = true;
	while (search) {
		//if open exits loop
		if (!scoreData.isPositionSet(posVector(highestCat))) {
			search = false;
		} else {
			//goes to next catagory and check if available
			highestCat++;
		}

	}

	//cycles through catatgory to see which is the best
	for (int i = 0; i < 13; i++) {
		//if the score for this cat with the current dice is better than the previous cycle, will set this catagory as the best
		//and is open
		if ((YahtzeeInterpreter::getScoreAs(posVector(i), dice)
				> YahtzeeInterpreter::getScoreAs(posVector(highestCat), dice))
				&& !scoreData.isPositionSet(posVector(i))) {
			highestCat = i;
		}
	}

	lastCatag = posVector(highestCat);
	lastPoints = YahtzeeInterpreter::getScoreAs(lastCatag, dice);
	scoreData.setPointsAtPosition(lastCatag, lastPoints);

	return lastCatag;
}

GreedyBot::~GreedyBot() {

}
