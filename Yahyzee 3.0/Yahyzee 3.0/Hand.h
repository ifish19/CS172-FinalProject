#ifndef HAND_H
#define HAND_H
#include<vector>
using namespace std;

class Hand
{
public:
	Hand();
	void setLockedDie(vector<int>);
	void rollHand();
	vector<int> getHand();
	int getSpecifiedHandValue(int);
	int getSize();
	// Sorts the hand from highest to lowest
	void sort();

private:
	vector<int> hand;
	vector<int> lockedDie;
	int size;

};

#endif