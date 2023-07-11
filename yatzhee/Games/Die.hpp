#ifndef DIE_DEF
#define DIE_DEF

#include <string>
#include "randgenerator.hpp"

class Die {
private:
	int value;
	int getAsValidValue(int proposed) const;
	Die(const Die &other);
	Die& operator=(const Die &other);
public:
	Die();
	Die(int value);
	void roll();
	int getValue() const;
	std::string getSymbolAsUnicode() const;
	~Die();
};

#endif /* DICE_HPP_ */
