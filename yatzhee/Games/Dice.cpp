#include "Dice.hpp"
#include <iostream>
using namespace std;

Dice::Dice() {
	// TODO implement
}

Dice::Dice(int numberOfDice) {
//for loop makes the specified die's
	for (int i = 0; i < numberOfDice; i++) {
		//new die instance made
		Die *d0 = new Die();
		//put into the vector array
		valueSet.push_back(d0);
	}
}

bool Dice::addDie(Die *die) {
	//for loop checks to see ifdie is already in the vector
	for (size_t i = 0; i < valueSet.size(); i++) {
		if (valueSet[i] == die) {
			return false;
		}
	}
	//puts it in the vector
	this->valueSet.push_back(die);
	return true;
}

Dice::Dice(std::vector<Die*> dice) {
	//assigns a new vector ass the addresses of the given vector
	for (size_t i = 0; i < dice.size(); i++) {
		this->valueSet.push_back(dice[i]);
	}
}

Dice Dice::getHighestMultiple() const {
	//initialise varaible for vector

	std::vector<int> placement;
	int one = 0;
	int two = 0;
	int three = 0;
	int four = 0;
	int five = 0;
	int six = 0;

	//tally up frequency of die roll
	for (size_t i = 0; i < valueSet.size(); i++) {
		if ((valueSet[i]->getValue()) == 1) {
			one++;
		} else if ((valueSet[i]->getValue()) == 2) {
			two++;
		} else if ((valueSet[i]->getValue()) == 3) {
			three++;
		} else if ((valueSet[i]->getValue()) == 4) {
			four++;
		} else if ((valueSet[i]->getValue()) == 5) {
			five++;
		} else if ((valueSet[i]->getValue()) == 6) {
			six++;
		}
	}
	//updates vector
	placement.push_back(six);
	placement.push_back(five);
	placement.push_back(four);
	placement.push_back(three);
	placement.push_back(two);
	placement.push_back(one);

	int num = 0;
	int freq = 0;

	//takes highest freq numb
	for (int i = 0; i < 6; i++) {
		if (placement[i] > freq) {
			freq = placement[i];
			num = (6 - i);
		}
	}

	Dice result = Dice();

	//makes dice class
	for (int i = 0; i < freq; i++) {
		Die *d1 = new Die(num);
		result.valueSet.push_back(d1);
	}

	return result;
}

int Dice::sum() const {

	int sum = 0;
	//goes through vector and adds values up
	for (size_t i = 0; i < valueSet.size(); i++) {
		sum = sum + valueSet[i]->getValue();
	}
	return sum;
}

int Dice::size() const {
	//returns the size
	return ((int) valueSet.size());
}

void Dice::rollAll() {
	//goes through vector and rolls all the die's
	for (size_t i = 0; i < valueSet.size(); i++) {
		Die *d = valueSet[i];
		d->roll();
	}
}

void Dice::printValues(std::string message, bool asSymbols,
		bool printNewLine) const {
	cout << message << " [";
	for (int i = 0; i < this->size(); i++) {
		if (asSymbols) {
			cout << getDie(i)->getSymbolAsUnicode();
		} else {
			cout << getDieValue(i);
		}
		if (i < size() - 1) {
			cout << ", ";
		}
	}
	cout << "]";
	if (printNewLine) {
		cout << endl;
	}
}

void Dice::rollAllBut(const Dice &diceSubset) {

	if (diceSubset.size() == 0) {
		this->rollAll();

	}
	//goes through all values of the dice instance
	for (size_t i = 0; i < valueSet.size(); i++) {
		//goes through all subset dice instances
		for (size_t n = 0; n < diceSubset.valueSet.size(); n++) {
			//if theyre the same die then exits loop for this die
			if (diceSubset.valueSet[n] == this->valueSet[i]) {
				break;
			}
			//if this die isnt part of the subset, rolls it
			else if (n == (diceSubset.valueSet.size() - 1)) {
				Die *d = valueSet[i];
				d->roll();
			}
		}
	}

}

int Dice::getDieValue(int ordinal) const {
	//returns value of this die
	Die *Dn = valueSet[ordinal];
	return (Dn->getValue());

}

Die* Dice::getDie(int ordinal) const {
	//returns the addy of this die
	return valueSet[ordinal];

}

Dice::~Dice() {

}
