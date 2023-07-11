#ifndef GREEDY_DEF
#define GREEDY_DEF

#include "Player.hpp"

class GreedyBot: public Player {
public:
	GreedyBot(const std::string &name, const Dice &dice);
	ScoreCard::Position playRound();
	virtual ~GreedyBot();
};

#endif
