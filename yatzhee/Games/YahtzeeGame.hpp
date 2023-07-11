#ifndef GAME_YAHTZEEGAME_HPP_
#define GAME_YAHTZEEGAME_HPP_

#include "Player.hpp"

class YahtzeeGame {
private:
	Player *player1;
	Player *player2;
	Dice dice;
	void printStatusSoFar(Player *player,
			ScoreCard::Position lastPositionPlayed) const;
public:
	YahtzeeGame(Player *player1, Player *player2, const Dice &dice);
	void play();
	virtual ~YahtzeeGame();
};

#endif /* GAME_YAHTZEEGAME_HPP_ */
