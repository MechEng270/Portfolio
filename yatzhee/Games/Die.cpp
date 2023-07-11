#include "Die.hpp"

using namespace std;

Die::Die() :
		Die(1) {
}

Die::Die(int value) {
	this->value = getAsValidValue(value);
}

void Die::roll() {
	this->value = RandomGenerator::rand() % 6 + 1;
}

int Die::getValue() const {
	return this->value;
}

std::string Die::getSymbolAsUnicode() const {
	switch (value) {
	case 1:
		return u8"\u2680";
		case 2:
		return u8"\u2681";
		case 3:
		return u8"\u2682";
		case 4:
		return u8"\u2683";
		case 5:
		return u8"\u2684";
		case 6:
		return u8"\u2685";
		default:
		return u8"\u2715";
	}
}

int Die::getAsValidValue(int proposed) const {
	if (proposed < 1 || proposed > 6) {
		return 1;
	}
	return proposed;
}

Die::~Die() {

}
