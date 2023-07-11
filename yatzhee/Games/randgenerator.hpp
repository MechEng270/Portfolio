#ifndef RANDOM_NUMBER_GENERATOR
#define RANDOM_NUMBER_GENERATOR

#include <cstdint>

/*
 * DO NOT MODIFY THIS FILE IN ANY WAY!
 */
class RandomGenerator {
private:
	const static int64_t a = 42519901547;
	const static int64_t b = 42420311819;
	const static int64_t mod = 2147483647;
	static int64_t current_value;

	static int as_absolute(int value);
	RandomGenerator();
public:
	static void setSeed(int seed);
	static int32_t rand();
};

#endif /* RANDOM_NUMBER_GENERATOR */
