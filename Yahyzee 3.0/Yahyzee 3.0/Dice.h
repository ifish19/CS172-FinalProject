#ifndef DICE_H	
#define DICE_H

class Dice
{
public:
	Dice(); // Creates a default die that has 6 sides
	Dice(int Nsides); // Cfeates a die with desired number of sides
	int roll(); // Rolls the die

private:
	int sides; // How many side the die has
};

#endif