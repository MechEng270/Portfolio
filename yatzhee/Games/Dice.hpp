#ifndef DICE_DEF
#define DICE_DEF

#include "Die.hpp"
#include <vector>
#include <string>

class Dice {
private:
	std::vector<Die*> valueSet;

public:
	Dice();
	Dice(int numberOfDice);
	Dice(std::vector<Die*> dice);

	bool addDie(Die *die);
	Die* getDie(int ordinal) const;
	int getDieValue(int ordinal) const;

	int sum() const;
	int size() const;

	void rollAll();
	void rollAllBut(const Dice &diceSubset);

	Dice getHighestMultiple() const;
	void printValues(std::string message, bool asSymbols,
			bool printNewLine) const;

	~Dice();
};

#endif /* end of include guard: DICE_DEF */
