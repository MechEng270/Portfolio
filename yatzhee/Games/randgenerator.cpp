#include "randgenerator.hpp"

/*
 * DO NOT MODIFY THIS FILE IN ANY WAY!
 */

int64_t RandomGenerator::current_value = 0;

RandomGenerator::RandomGenerator() {
}

int RandomGenerator::as_absolute(int value) {
	if (value < 0) {
		return value * -1;
	}
	return value;
}

void RandomGenerator::setSeed(int seed) {
	current_value = seed;
}

int32_t RandomGenerator::rand() {
	current_value = as_absolute((a * current_value + b) % mod);
	return current_value;
}
