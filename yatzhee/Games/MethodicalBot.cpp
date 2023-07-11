#include "MethodicalBot.hpp"
#include <iostream>
using namespace std;
MethodicalBot::MethodicalBot(const std::string &name, const Dice &dice) :
		Player(name, dice) {
}

ScoreCard::Position MethodicalBot::playRound() {

	//round = 12;
	//roll the dice
	dice.rollAll();
	Player::rolled(name, dice);
	lastCatag = posVector(round);

	if (round < 6) {
		//rolls dice 2 additional times
		for (int n = 0; n < 2; n++) {
			//dice subset of die's not to roll initialised
			Dice rollnt = Dice();
			//cycles through dice
			for (int i = 0; i < 5; i++) {
				//if any die in the roll is this rounds value, will set it to the subset
				if (dice.getDieValue(i) == (round + 1)) {
					rollnt.addDie(dice.getDie(i));
				}
			}

			Player::holds(dice, rollnt);
			dice.rollAllBut(rollnt);
			Player::rolled(name, dice);
		}

		lastPoints = YahtzeeInterpreter::getScoreAs(lastCatag, dice);
		//write down the data into the scorecard
		scoreData.setPointsAtPosition(lastCatag, lastPoints);
		round++;
		return lastCatag;
	} else if (round == 6 || round == 7) {

		//desired number
		int num = 1;

		for (int n = 0; n < 2; n++) {
			//dice subset of die's not to roll initialised
			Dice rollnt = Dice();
			//cycles through dice
			//if it finds a triple or higher, will set the desired num to that
			if (dice.getHighestMultiple().size() >= 3) {
				num = dice.getHighestMultiple().getDieValue(0);
			}

			for (int i = 0; i < 5; i++) {
				//if any die in the roll is 1 or that got tripled, will set it to the subset
				if (dice.getDieValue(i) == (num)) {
					rollnt.addDie(dice.getDie(i));
				}
			}

			Player::holds(dice, rollnt);
			dice.rollAllBut(rollnt);
			Player::rolled(name, dice);
		}

		lastPoints = YahtzeeInterpreter::getScoreAs(lastCatag, dice);
		//write down the data into the scorecard
		scoreData.setPointsAtPosition(lastCatag, lastPoints);
		round++;
		return lastCatag;

	} else if (round == 8 || round == 9) {

		for (int n = 0; n < 2; n++) {
			//dice subset of die's not to roll initialised
			Dice rollnt = Dice();

			//if small straight work then it works
			if (YahtzeeInterpreter::getScoreAs(lastCatag, dice) != 0) {
				lastPoints = YahtzeeInterpreter::getScoreAs(lastCatag, dice);
				//write down the data into the scorecard
				scoreData.setPointsAtPosition(lastCatag, lastPoints);
				round++;
				return lastCatag;
			}

			//out of all the neccessary numbers needed for the hand, this vector shows which are open
			std::vector<bool> holdOpen;

			for (int k = 0; k < (round - 4); k++) {
				holdOpen.push_back(true);
			}

			//cycles through dice
			for (int i = 0; i < 5; i++) {
				//check all neccessary values
				for (int j = 1; j <= (round - 4); j++) {
					//if number isnt already claimed and the dice is the needed value
					if (holdOpen[j - 1] && dice.getDieValue(i) == j) {
						//adds die to the holds
						rollnt.addDie(dice.getDie(i));
						holdOpen[j - 1] = false;
					}
				}
			}

			Player::holds(dice, rollnt);
			dice.rollAllBut(rollnt);
			Player::rolled(name, dice);
		}

		lastPoints = YahtzeeInterpreter::getScoreAs(lastCatag, dice);
		//write down the data into the scorecard
		scoreData.setPointsAtPosition(lastCatag, lastPoints);
		round++;
		return lastCatag;

	} else if (round == 10) {

		//desired number
		int num = dice.getHighestMultiple().getDieValue(0);

		for (int n = 0; n < 2; n++) {

			Dice rollnt = Dice();

			if (YahtzeeInterpreter::getScoreAs(lastCatag, dice) == 25) {
				lastPoints = YahtzeeInterpreter::getScoreAs(lastCatag, dice);
				//write down the data into the scorecard
				scoreData.setPointsAtPosition(lastCatag, lastPoints);
				round++;
				return lastCatag;
			}

			//if it has a 3 of a kind
			if (dice.getHighestMultiple().size() == 3) {
				num = dice.getHighestMultiple().getDieValue(0);

				//will find the die not 3 of a kind and reroll it
				for (int i = 0; i < 5; i++) {

					if (dice.getDieValue(i) == (num)) {
						rollnt.addDie(dice.getDie(i));

					}
					//if no multiples will hold onto the highest number
				}
			} else if (dice.getHighestMultiple().size() < 3) {
				for (int i = 0; i < 5; i++) {
					num = dice.getHighestMultiple().getDieValue(0);

					if (dice.getDieValue(i) == (num)) {
						rollnt.addDie(dice.getDie(i));

					}
				}
			} else if (dice.getHighestMultiple().size() > 3) {
				num = dice.getHighestMultiple().getDieValue(0);

				int placeholder = 0;
				//takes first 3 instances of the multiple number popping up

				for (int i = 0; i < 5; i++) {
					if (placeholder > 2) {
						break;

					}
					;
					if (dice.getDieValue(i) == (num)) {

						rollnt.addDie(dice.getDie(i));
						placeholder++;

					}
				}
			}

			Player::holds(dice, rollnt);
			dice.rollAllBut(rollnt);
			Player::rolled(name, dice);
		}

		lastPoints = YahtzeeInterpreter::getScoreAs(lastCatag, dice);
		//write down the data into the scorecard
		scoreData.setPointsAtPosition(lastCatag, lastPoints);
		round++;
		return lastCatag;

	} else if (round == 11) {

		//rolls twice
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
			//rolls the rest

			Player::holds(dice, rollnt);
			dice.rollAllBut(rollnt);
			Player::rolled(name, dice);
		}

		lastPoints = YahtzeeInterpreter::getScoreAs(lastCatag, dice);
		//write down the data into the scorecard
		scoreData.setPointsAtPosition(lastCatag, lastPoints);
		round++;
		return lastCatag;

	} else if (round == 12) {
		for (int n = 0; n < 2; n++) {

			Dice rollnt = Dice();

			for (int i = 0; i < 5; i++) {

				if (dice.getDieValue(i) > 3) {
					rollnt.addDie(dice.getDie(i));
				}

			}

			Player::holds(dice, rollnt);
			dice.rollAllBut(rollnt);
			Player::rolled(name, dice);
		}

		lastPoints = YahtzeeInterpreter::getScoreAs(lastCatag, dice);
		//write down the data into the scorecard
		scoreData.setPointsAtPosition(lastCatag, lastPoints);
		round++;
		return lastCatag;

	}
	return ScoreCard::NOT_SET;
}

MethodicalBot::~MethodicalBot() {
}
