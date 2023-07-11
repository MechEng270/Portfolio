#ifndef GAME_AMATEURBOT_HPP_
#define GAME_AMATEURBOT_HPP_

#include "Player.hpp"
#include <string>

class AmateurBot: public Player {
public:

	AmateurBot(const std::string &name, const Dice &dice);
	virtual ScoreCard::Position playRound();
	virtual ~AmateurBot();
};

#endif /* GAME_AMATEURBOT_HPP_ */
