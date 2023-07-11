#include "YahtzeeInterpreter.hpp"
#include <iostream>
using namespace std;

int YahtzeeInterpreter::getScoreAs(ScoreCard::Position position,
		const Dice &dice) {
	if (dice.size() != 5) {
		return -1;
	}

	if (position == ScoreCard::ONES || position == 1) {
		return getScoreAsValue(dice, 1);
	} else if (position == ScoreCard::TWOS) {
		return getScoreAsValue(dice, 2);
	} else if (position == ScoreCard::THREES) {
		return getScoreAsValue(dice, 3);
	} else if (position == ScoreCard::FOURS) {
		return getScoreAsValue(dice, 4);
	} else if (position == ScoreCard::FIVES) {
		return getScoreAsValue(dice, 5);
	} else if (position == ScoreCard::SIXES) {
		return getScoreAsValue(dice, 6);
	} else if (position == ScoreCard::THREE_OF_A_KIND) {
		return getScoreAsThreeOfAKind(dice);
	} else if (position == ScoreCard::FOUR_OF_A_KIND) {
		return getScoreAsFourOfAKind(dice);
	} else if (position == ScoreCard::SMALL_STRAIGHT) {
		return getScoreAsSmallStraight(dice);
	} else if (position == ScoreCard::LARGE_STRAIGHT) {
		return getScoreAsLargeStraight(dice);
	} else if (position == ScoreCard::FULL_HOUSE) {
		return getScoreAsFullHouse(dice);
	} else if (position == ScoreCard::YAHTZEE) {
		return getScoreAsYahtzee(dice);
	} else if (position == ScoreCard::CHANCE) {
		return getScoreAsChance(dice);
	} else {
		return 0;
	}
}

int YahtzeeInterpreter::getScoreAsValue(const Dice &dice, int value) {

	if (dice.size() != 5) {
		return -1;
	}

	int freq = 0;
//finds freq of the specified value
	for (int i = 0; i < dice.size(); i++) {
		if (dice.getDieValue(i) == value) {
			freq++;
		}
	}
//sums values
	int score = freq * value;

	return score;
}

int YahtzeeInterpreter::getScoreAsThreeOfAKind(const Dice &dice) {

	if (dice.size() != 5) {
		return -1;
	}
//if not atleast 3, returns 0
	Dice d1 = dice.getHighestMultiple();
	if (d1.size() < 3) {
		return 0;
	}
	return dice.sum();
}

int YahtzeeInterpreter::getScoreAsFourOfAKind(const Dice &dice) {
	if (dice.size() != 5) {
		return -1;
	}

//if not atleast 3, returns 0
	Dice d1 = dice.getHighestMultiple();
	if (d1.size() < 4) {
		return 0;
	}
	return dice.sum();

}

int YahtzeeInterpreter::getScoreAsSmallStraight(const Dice &dice) {
	if (dice.size() != 5) {
		return -1;
	}
// its 2am in the morning
	for (int a = 1; a < 4; a++) {

		for (int i = 0; i < dice.size(); i++) {
			if (dice.getDieValue(i) == a) {

				for (int n = 0; n < dice.size(); n++) {
					if (dice.getDieValue(n) == a + 1) {

						for (int j = 0; j < dice.size(); j++) {
							if (dice.getDieValue(j) == a + 2) {

								for (int k = 0; k < dice.size(); k++) {
									if (dice.getDieValue(k) == a + 3) {
										return 30;
									}
								}
							}
						}
					}
				}
			}

		}
	}
	return 0;
}

int YahtzeeInterpreter::getScoreAsLargeStraight(const Dice &dice) {

	if (dice.size() != 5) {
		return -1;
	}

//im sleep deprived
	for (int a = 1; a < 3; a++) {

		for (int i = 0; i < dice.size(); i++) {
			if (dice.getDieValue(i) == a) {

				for (int n = 0; n < dice.size(); n++) {
					if (dice.getDieValue(n) == a + 1) {

						for (int j = 0; j < dice.size(); j++) {
							if (dice.getDieValue(j) == a + 2) {

								for (int k = 0; k < dice.size(); k++) {
									if (dice.getDieValue(k) == a + 3) {

										for (int k = 0; k < dice.size(); k++) {
											if (dice.getDieValue(k) == a + 4) {
												return 40;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}

int YahtzeeInterpreter::getScoreAsFullHouse(const Dice &dice) {

	if (dice.size() != 5) {
		return -1;
	}

	int a = 0;
	int b = 0;
//if no 3's give 0
	if (dice.getHighestMultiple().size() != 3) {
		return 0;
	} else {
		//if the remaining 2 numbers are the same
		for (int i = 0; i < 5; i++) {
			if (dice.getDieValue(i) != dice.getHighestMultiple().getDieValue(0)
					&& a == 0) {
				a = dice.getDieValue(i);
			} else if (dice.getDieValue(i)
					!= dice.getHighestMultiple().getDieValue(0)) {
				b = dice.getDieValue(i);
			}
		}
		//eill retrun zero
		if (a == b) {
			return 25;
		}

	}
//else will return 0
	return 0;
}

int YahtzeeInterpreter::getScoreAsYahtzee(const Dice &dice) {
	if (dice.size() != 5) {
		return -1;
	}
//if not 5 of the same dies, returns 0
	Dice d1 = dice.getHighestMultiple();
	if (d1.size() != 5) {
		return 0;
	}
//returns yahtzee
	return 50;
}

int YahtzeeInterpreter::getScoreAsChance(const Dice &dice) {
// TODO implement
	if (dice.size() != 5) {
		return -1;
	}

	return dice.sum();
}

