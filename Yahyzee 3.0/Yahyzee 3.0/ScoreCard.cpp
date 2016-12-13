#include"ScoreCard.h"

ScoreCard::ScoreCard()
{
	lowerScore = 0;
	upperScore = 0;
	Chances = 0;
	FourOfAKinds = 0;
	FullHouses = 0;
	LargeStraights = 0;
	SmallStraights = 0;
	ThreeOfAKinds = 0;
	Yhatzees = 0;
	Aces = 0;
	Twos = 0;
	Threes = 0;
	Fours = 0;
	Fives = 0;
	Sixes = 0;
}

int ScoreCard::getLowerScore()
{
	return lowerScore;
}

int ScoreCard::getUpperScore()
{
	return upperScore;
}

int ScoreCard::getTotalScore()
{
	if(upperScore >= 63)
		upperScore += 35;
	return upperScore + lowerScore;
}

int ScoreCard::getAces() { return Aces; }

int ScoreCard::getTwos() { return Twos; }

int ScoreCard::getThrees() { return Threes; }

int ScoreCard::getFours() { return Fours; }

int ScoreCard::getFives() { return Fives; }

int ScoreCard::getSixes() { return Sixes; }

int ScoreCard::getThreeOfAKinds() { return ThreeOfAKinds; }

int ScoreCard::getFourOfAKinds() { return FourOfAKinds; }

int ScoreCard::getFullHouses() { return FullHouses; }

int ScoreCard::getSmallStraights() { return SmallStraights; }

int ScoreCard::getLargeStraights() { return LargeStraights; }

int ScoreCard::getYhatzees() { return Yhatzees; }

int ScoreCard::getChances() { return Chances; }

void ScoreCard::ThreeOfAKind(Hand hand)
{
	int n = 0;
	int sum = 0;
	for (int i = 0; i < hand.getSize(); i++) 
	{
		for (int j = 0; j < hand.getSize(); j++) 
		{
			if (hand.getSpecifiedHandValue(i) == hand.getSpecifiedHandValue(j))
				n += 1;
		}
		if (n >= 3)
		{
			for (int k = 0; k < hand.getSize(); k++)
			{
				sum += hand.getSpecifiedHandValue(k);
			}
			lowerScore += sum;
			break;
		}
		else
			n = 0;
	}

	ThreeOfAKinds++;
}

void ScoreCard::FourOfAKind(Hand hand)
{
	int n = 0;
	int sum = 0;
	for (int i = 0; i < hand.getSize(); i++) 
	{
		for (int j = 0; j < hand.getSize(); j++) 
		{
			if (hand.getSpecifiedHandValue(i) == hand.getSpecifiedHandValue(j))
				n += 1;
		}
		if (n >= 4)
		{
			for (int k = 0; k < hand.getSize(); k++)
			{
				sum += hand.getSpecifiedHandValue(k);
			}
			lowerScore += sum;
			break;
		}
		else
			n = 0;
	}

	FourOfAKinds++;
}

void ScoreCard::SmallStraight(Hand hand)
{
	hand.sort();
	
	int n = 0;
	for (int i = 0; i < hand.getSize(); i++)
	{
		if (hand.getSpecifiedHandValue(i) == (hand.getSpecifiedHandValue( i + 1) + 1))
		{
			n = n + 1;
		}
	}
	if (n == 3)
	{
		lowerScore += 30;
	}

	SmallStraights++;
}

void ScoreCard::LargeStraight(Hand hand)
{
	hand.sort();
	
	int n = 0;
	for (int i = 0; i < hand.getSize(); i++)
	{
		if (hand.getSpecifiedHandValue(i) == (hand.getSpecifiedHandValue( i + 1) + 1))
		{
			n = n + 1;
		}
	}
	if (n == 4)
	{
		lowerScore += 40;
	}

	LargeStraights++;
}

void ScoreCard::FullHouse(Hand hand)
{
	hand.sort();

	int n = 0;
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		if (hand.getSpecifiedHandValue(0) == hand.getSpecifiedHandValue(i))
			n++;
	}
	
	if (n == 3)
	{
		if (hand.getSpecifiedHandValue(3) == hand.getSpecifiedHandValue(4))
			lowerScore += 25;
	}
	else if (n == 2)
	{
		if (hand.getSpecifiedHandValue(2) == hand.getSpecifiedHandValue(3) && hand.getSpecifiedHandValue(3) == hand.getSpecifiedHandValue(4))
			lowerScore += 25;
	}
	
	FullHouses++;
}

void ScoreCard::Chance(Hand hand)
{
	int sum = 0;
	for (int i = 0; i < hand.getSize(); i++)
		sum += hand.getSpecifiedHandValue(0);

	lowerScore += sum;
	Chances++;
}

void ScoreCard::Yhatzee(Hand hand)
{
	int n = 0;
	for (int i = 0; i < hand.getSize(); i++) 
	{
		for (int j = 0; j < hand.getSize(); j++) 
		{
			if (hand.getSpecifiedHandValue(i) == hand.getSpecifiedHandValue(j))
				n += 1;
		}
		if (n == 5)
		{
			if (Yhatzees >= 1)
				lowerScore += 100;
			else
				lowerScore += 50;
			break;
		}
		else
			n = 0;
	}
	Yhatzees++;
}

void ScoreCard::UpperScores(Hand hand, int value)
{
	int sum = 0;
	for (int i = 0; i < hand.getSize(); i++) {
		if (hand.getSpecifiedHandValue(i) == value) {
			sum += value;
		}
	}
	if (value == 1)
		Aces++;
	else if (value == 2)
		Twos++;
	else if (value == 3)
		Threes++;
	else if (value == 4)
		Fours++;
	else if (value == 5)
		Fives++;
	else if (value == 6)
		Sixes++;

	upperScore += sum;
}