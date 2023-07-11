#ifndef GAME_HUMANPLAYER_HPP_
#define GAME_HUMANPLAYER_HPP_

#include "Player.hpp"
#include <string>

class HumanPlayer: public Player {
public:
	HumanPlayer(const std::string &name, const Dice &dice);
	virtual ScoreCard::Position playRound();
	virtual ~HumanPlayer();
};

#endif /* GAME_HUMANPLAYER_HPP_ */
