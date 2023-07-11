#include "ScoreCard.hpp"
#include <iostream>
using namespace std;

ScoreCard::ScoreCard() {
	//makes empty score card with 0 for all
	for (int i = 0; i < 13; i++) {
		this->score.push_back(0);
		this->cat.push_back(1);
	}
}

int ScoreCard::vectorPos(Position position) {

	int cat_num = -1;
	//converts position to number to access score vector
	if (position == ScoreCard::ONES || position == 1) {
		cat_num = 0;
	} else if (position == ScoreCard::TWOS) {
		cat_num = 1;
	} else if (position == ScoreCard::THREES) {
		cat_num = 2;
	} else if (position == ScoreCard::FOURS) {
		cat_num = 3;
	} else if (position == ScoreCard::FIVES) {
		cat_num = 4;
	} else if (position == ScoreCard::SIXES) {
		cat_num = 5;
	} else if (position == ScoreCard::THREE_OF_A_KIND) {
		cat_num = 6;
	} else if (position == ScoreCard::FOUR_OF_A_KIND) {
		cat_num = 7;
	} else if (position == ScoreCard::SMALL_STRAIGHT) {
		cat_num = 8;
	} else if (position == ScoreCard::LARGE_STRAIGHT) {
		cat_num = 9;
	} else if (position == ScoreCard::FULL_HOUSE) {
		cat_num = 10;
	} else if (position == ScoreCard::YAHTZEE) {
		cat_num = 11;
	} else if (position == ScoreCard::CHANCE) {
		cat_num = 12;
	}
	return cat_num;
}

bool ScoreCard::setPointsAtPosition(Position position, int points) {
	int cat_num = vectorPos(position);

	//
	if (this->cat[cat_num] == 1) {
		this->score[cat_num] = points;
		this->cat[cat_num] = 0;
		return true;
	}

	return false;
}

bool ScoreCard::isPositionSet(Position position) const {
	int cat_num = vectorPos(position);
	//if the catagorie vector says its full, will return true, otherwise will return false
	if (this->cat[cat_num] == 0) {
		return true;

	}
	return false;
}

bool ScoreCard::isComplete() const {
	//goes through cat vector

	for (int i = 0; i < 13; i++) {
		//if at any point, the availible catagorie vecotr has an open catagory, will return false
		if (this->cat[i] != 0) {
			return false;
		}
	}
	//if all are taken then returns true
	return true;
}

int ScoreCard::getPointsAtPosition(Position position) const {
	//simple stuff
	return score[vectorPos(position)];
}

int ScoreCard::getPointsTotal() const {
	int sum = 0;

	for (int i = 0; i < 13; i++) {
		sum = sum + this->score[i];
	}

	return sum;
}

std::string ScoreCard::getPositionName(Position position) {
	switch (position) {
	case ScoreCard::Position::ONES:
		return "ONES";
	case ScoreCard::Position::TWOS:
		return "TWOS";
	case ScoreCard::Position::THREES:
		return "THREES";
	case ScoreCard::Position::FOURS:
		return "FOURS";
	case ScoreCard::Position::FIVES:
		return "FIVES";
	case ScoreCard::Position::SIXES:
		return "SIXES";
	case ScoreCard::Position::THREE_OF_A_KIND:
		return "THREE OF A KIND";
	case ScoreCard::Position::FOUR_OF_A_KIND:
		return "FOUR OF A KIND";
	case ScoreCard::Position::SMALL_STRAIGHT:
		return "SMALL STRAIGHT";
	case ScoreCard::Position::LARGE_STRAIGHT:
		return "LARGE STRAIGHT";
	case ScoreCard::Position::FULL_HOUSE:
		return "FULL HOUSE";
	case ScoreCard::Position::YAHTZEE:
		return "YAHTZEE";
	case ScoreCard::Position::CHANCE:
		return "CHANCE";
	default:
		return "INVALID POSITION";
	}
}

ScoreCard::~ScoreCard() {

}
