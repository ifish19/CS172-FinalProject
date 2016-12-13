#ifndef SCORE_H
#define SCORE_H
#include<vector>
#include"Hand.h"
using namespace std;

class ScoreCard
{
public:
	ScoreCard();
	int getLowerScore();
	int getUpperScore();
	int getTotalScore();
	int getYhatzees();
	int getThreeOfAKinds();
	int getFourOfAKinds();
	int getSmallStraights();
	int getLargeStraights();
	int getFullHouses();
	int getChances();
	int getAces();
	int getTwos();
	int getThrees();
	int getFours();
	int getFives();
	int getSixes();
	void ThreeOfAKind(Hand);
	void FourOfAKind(Hand);
	void SmallStraight(Hand);
	void LargeStraight(Hand);
	void FullHouse(Hand);
	void Chance(Hand);
	void Yhatzee(Hand);
	void UpperScores(Hand, int);

private:
	int lowerScore;
	int upperScore;
	int Yhatzees;
	int ThreeOfAKinds;
	int FourOfAKinds;
	int SmallStraights;
	int LargeStraights;
	int FullHouses;
	int Chances;
	int Aces;
	int Twos;
	int Threes;
	int Fours;
	int Fives;
	int Sixes;
};

#endif