#include "Player.hpp"
#include <iostream>
#include <string>
using namespace std;

Player::Player(const std::string &name, const Dice &dice) {
	this->name = name;
	this->dice = dice;
	this->scoreData = ScoreCard();
	this->lastCatag = ScoreCard::NOT_SET;
	this->round = 0;
	this->lastPoints = 0;

}

std::string Player::getName() const {

	return this->name;
}

bool Player::hasRemainingRounds() const {
	//if scorecard filled, returns false
	if (scoreData.isComplete()) {
		return false;

	}
	return true;
}

int Player::getPointsLastRound() const {
	//returns points of last round
	return lastPoints;
}

int Player::getPointsTotal() const {
//returns scorecard sum
	return scoreData.getPointsTotal();;
}

ScoreCard::Position Player::posVector(int pos) {

//converts number to pos on corrosponding scorecard
	if (pos == 0) {
		return ScoreCard::ONES;
	} else if (pos == 1) {
		return ScoreCard::TWOS;
	} else if (pos == 2) {
		return ScoreCard::THREES;
	} else if (pos == 3) {
		return ScoreCard::FOURS;
	} else if (pos == 4) {
		return ScoreCard::FIVES;
	} else if (pos == 5) {
		return ScoreCard::SIXES;
	} else if (pos == 6) {
		return ScoreCard::THREE_OF_A_KIND;
	} else if (pos == 7) {
		return ScoreCard::FOUR_OF_A_KIND;
	} else if (pos == 8) {
		return ScoreCard::SMALL_STRAIGHT;
	} else if (pos == 9) {
		return ScoreCard::LARGE_STRAIGHT;
	} else if (pos == 10) {
		return ScoreCard::FULL_HOUSE;
	} else if (pos == 11) {
		return ScoreCard::YAHTZEE;
	} else if (pos == 12) {
		return ScoreCard::CHANCE;
	} else {
		return ScoreCard::NOT_SET;
	}

}
std::string Player::posString(int pos) {
	//converts number to pos on corrosponding scorecard
	if (pos == 0) {
		return "ONES";
	} else if (pos == 1) {
		return "TWOS";
	} else if (pos == 2) {
		return "THREES";
	} else if (pos == 3) {
		return "FOURS";
	} else if (pos == 4) {
		return "FIVES";
	} else if (pos == 5) {
		return "SIXES";
	} else if (pos == 6) {
		return "THREE OF A KIND";
	} else if (pos == 7) {
		return "FOUR OF A KIND";
	} else if (pos == 8) {
		return "SMALL STRAIGHT";
	} else if (pos == 9) {
		return "LARGE STRAIGHT";
	} else if (pos == 10) {
		return "FULL HOUSE";
	} else if (pos == 11) {
		return "YAHTZEE";
	} else if (pos == 12) {
		return "CHANCE";
	} else {
		return "NOT SET";
	}

}

void Player::rolled(const std::string &name, const Dice &dice) {

	cout << name << " rolled:  [" << dice.getDieValue(0) << ", "
			<< dice.getDieValue(1) << ", " << dice.getDieValue(2) << ", "
			<< dice.getDieValue(3) << ", " << dice.getDieValue(4) << "]"
			<< endl;
}

void Player::rolled2(const std::string &name, const Dice &dice, int num) {

	if (num == 0) {
		cout << name << "'s first roll [" << dice.getDieValue(0) << ", "
				<< dice.getDieValue(1) << ", " << dice.getDieValue(2) << ", "
				<< dice.getDieValue(3) << ", " << dice.getDieValue(4) << "]"
				<< endl;
	} else if (num == 1) {
		cout << name << "'s second roll [" << dice.getDieValue(0) << ", "
				<< dice.getDieValue(1) << ", " << dice.getDieValue(2) << ", "
				<< dice.getDieValue(3) << ", " << dice.getDieValue(4) << "]"
				<< endl;
	} else if (num == 2) {
		cout << name << "'s final roll [" << dice.getDieValue(0) << ", "
				<< dice.getDieValue(1) << ", " << dice.getDieValue(2) << ", "
				<< dice.getDieValue(3) << ", " << dice.getDieValue(4) << "]"
				<< endl;
	} else {

		cout << name << "'s extra roll [" << dice.getDieValue(0) << ", "
				<< dice.getDieValue(1) << ", " << dice.getDieValue(2) << ", "
				<< dice.getDieValue(3) << ", " << dice.getDieValue(4) << "]"
				<< endl;

	}

}

void Player::holds(const Dice &dice, const Dice &diceSubset) {
	vector<int> holds;

	//goes through all values of the dice instance
	for (int i = 0; i < dice.size(); i++) {
		//goes through all subset dice instances
		for (int n = 0; n < diceSubset.size(); n++) {
			//if theyre the same die then exits loop for this die
			if (diceSubset.getDie(n) == dice.getDie(i)) {
				holds.push_back(i);
				n = diceSubset.size();
				break;
			}
		}
	}

	// prints the dice being held
	cout << "dice held are: [";
	for (size_t j = 0; j < holds.size(); j++) {
		cout << dice.getDieValue(holds[j]);

		if (j < (holds.size() - 1)) {
			cout << ", ";
			;

		}
	}
	cout << "]" << endl;
}

Player::~Player() {
}
