#ifndef YAHTZEEINTERPRETER_DEF
#define YAHTZEEINTERPRETER_DEF

#include "Dice.hpp"
#include "ScoreCard.hpp"

class YahtzeeInterpreter {
private:
	YahtzeeInterpreter();

public:

	static int getScoreAs(ScoreCard::Position position, const Dice &dice);
	static int getScoreAsValue(const Dice &dice, int value);
	static int getScoreAsThreeOfAKind(const Dice &dice);
	static int getScoreAsFourOfAKind(const Dice &dice);
	static int getScoreAsFullHouse(const Dice &dice);
	static int getScoreAsSmallStraight(const Dice &dice);
	static int getScoreAsLargeStraight(const Dice &dice);
	static int getScoreAsYahtzee(const Dice &dice);
	static int getScoreAsChance(const Dice &dice);
};

#endif /* YAHTZEEINTERPRETER_DEF */
