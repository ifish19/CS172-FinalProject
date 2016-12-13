#include "Hand.h"
#include "Dice.h"
#include<ctime>
#include<iostream>
using namespace std;

Hand::Hand()
{
	size = 5;
	for (int i = 0; i < size; i++)
	{
		hand.push_back(-1);
		lockedDie.push_back(-1);
	}
}

void Hand::setLockedDie(vector<int> locked)
{
	lockedDie.clear();
	for (int i = 0; i < size; i++)
		lockedDie.push_back(locked[i]);
}

void Hand::rollHand()
{
	srand(time(NULL));
	hand.clear();
	for (int i = 0; i < size; i++)
	{
		Dice* d = new Dice();
		// cout << d->roll() << endl;
		if (lockedDie[i] == -1)
			hand.push_back(d->roll());
		else
			hand.push_back(lockedDie[i]);
		delete d;
	}
}

vector<int> Hand::getHand()
{
	return hand;
}

int Hand::getSize()
{
	return size;
}

void Hand::sort()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int z = j;
			if (hand[j] < hand[j + 1])
			{
				z = hand[j];
				hand[j] = hand[j + 1];
				hand[j + 1] = z;
			}
		}
	}
}

int Hand::getSpecifiedHandValue(int value)
{
	return hand[value];
}