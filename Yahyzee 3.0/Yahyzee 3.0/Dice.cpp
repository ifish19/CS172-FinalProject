#include "Dice.h"
#include<time.h>
#include<stdlib.h>
using namespace std;

Dice::Dice()
{
	sides = 6;
}

Dice::Dice(int Nsides)
{
	sides = Nsides;
}

int Dice::roll()
{
	int value = rand() % sides + 1;
	return value;
}