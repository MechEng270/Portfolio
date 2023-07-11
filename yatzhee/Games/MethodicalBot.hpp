#ifndef METHODICAL_DEF
#define METHODICAL_DEF

#include "Player.hpp"

class MethodicalBot: public Player {

public:
	MethodicalBot(const std::string &name, const Dice &dice);
	virtual ScoreCard::Position playRound();
	virtual ~MethodicalBot();
};

#endif
