#ifndef PLAYER_DEF
#define PLAYER_DEF

#include "YahtzeeInterpreter.hpp"
#include "ScoreCard.hpp"
#include <vector>
#include <string>

class Player {
protected:
	std::string name;
	Dice dice;
	ScoreCard scoreData;
	int round;
	ScoreCard::Position lastCatag;
	int lastPoints;
	static ScoreCard::Position posVector(int pos);
	static std::string posString(int pos);
	static void rolled(const std::string &name, const Dice &dice);
	static void rolled2(const std::string &name, const Dice &dice, int num);
	static void holds(const Dice &dice, const Dice &diceSubset);

public:
	Player(const std::string &name, const Dice &dice);
	std::string getName() const;
	bool hasRemainingRounds() const;
	int getPointsTotal() const;
	int getPointsLastRound() const;

	virtual ScoreCard::Position playRound() = 0;
	virtual ~Player();
};

#endif /* PLAYER_DEF */
