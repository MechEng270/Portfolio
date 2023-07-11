#ifndef SCORECARD_DEF
#define SCORECARD_DEF

#include <string>
#include <vector>

class ScoreCard {
private:
	//creates vectors for avaible catagories and scores
	std::vector<int> score;
	std::vector<int> cat;

public:
	enum Position {
		NOT_SET = -1,
		ONES = 1,
		TWOS,
		THREES,
		FOURS,
		FIVES,
		SIXES,
		THREE_OF_A_KIND,
		FOUR_OF_A_KIND,
		SMALL_STRAIGHT,
		LARGE_STRAIGHT,
		FULL_HOUSE,
		YAHTZEE,
		CHANCE,
		MAX
	};

	ScoreCard();

	static int vectorPos(Position position);
	bool isPositionSet(Position position) const;
	int getPointsAtPosition(Position position) const;
	bool setPointsAtPosition(Position position, int points);

	bool isComplete() const;
	int getPointsTotal() const;

	static std::string getPositionName(Position position);
	~ScoreCard();
};

#endif /* SCORECARD_DEF */
