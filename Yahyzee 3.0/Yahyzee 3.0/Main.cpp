#include<iostream>
#include<ctime>
#include"Dice.h"
#include"ScoreCard.h"
#include"Hand.h"
#include<fstream>
using namespace std;

int main() {
	// Create a new blank scorecard
	ScoreCard* s = new ScoreCard();
	
	// Check if there are any turns left
	while (s->getAces() == 0 || s->getTwos() == 0 || s->getThrees() == 0 || s->getFours() == 0 || s->getFives() == 0 || s->getSixes() == 0 
		|| s->getThreeOfAKinds() == 0 || s->getFourOfAKinds() == 0 || s->getFullHouses() == 0 || s->getSmallStraights() == 0 
		|| s->getLargeStraights() == 0 || s->getChances() == 0 || s->getYhatzees() == 0)
	{
		// Commence Turn

		// Create a new hand
		Hand* h = new Hand();
		char reRoll = 'n';
		int rolls = 0;
		do
		{
			vector<int>* lockedDie = new vector<int>;
			h->rollHand();
			for (int i = 0; i < h->getSize(); i++)
				cout << h->getSpecifiedHandValue(i) << " | ";
			cout << endl;
			for (int j = 0; j < h->getSize(); j++) 
			{
				char lockDie = 'n';
				cout << "Do you want to lock die " << j + 1 << "? y/n: ";
				cin >> lockDie;
				if (lockDie == 'y')
					lockedDie->push_back(h->getSpecifiedHandValue(j));
				else
					lockedDie->push_back(-1);
			}
			h->setLockedDie(*lockedDie);
			delete lockedDie;
			if (rolls < 2)
			{
				cout << "Roll again? y/n? ";
				cin >> reRoll;
			}
			else
				reRoll = 'n';
		}
		while (reRoll == 'y' && rolls < 3);

		// Score turn
		int chooseUpLow;
		int chooseSubCat;
		int retry = 0;
		cout << "Choose how to score your dice." << endl;
		cout << "UPPER SCORES:" << endl;
		cout << "\t1)Ones\n";
		cout << "\t2)Twos\n";
		cout << "\t3)Threes\n";
		cout << "\t4)Fours\n";
		cout << "\t5)Fives\n";
		cout << "\t6)Sixes\n";
		cout << "LOWER SCORES:\n";
		cout << "\t1)Three of a Kind\n";
		cout << "\t2)Four of a Kind\n";
		cout << "\t3)Small Straight\n";
		cout << "\t4)Large Straight\n";
		cout << "\t5)Full House\n";
		cout << "\t6)Yahtzee\n";
		cout << "\t7)Chance\n";
		do{
			retry = 0;
			cout << "Choose Upper Scores(1) or Lower Scores(2)\n";
			cin >> chooseUpLow;
			if (chooseUpLow == 1) 
			{
				cout << "Choose a sub category 1-6 as listed above: " << endl;
				cin >> chooseSubCat;
				switch (chooseSubCat) 
				{
				case 1: 
					if(s->getAces() == 0)
						s->UpperScores(*h,1);
					else
					{
						cout << "You have already chosen this!" << endl;
						retry = 1;
					}
					break;
				case 2:
					if(s->getTwos() == 0)
						s->UpperScores(*h,2);
					else
					{
						cout << "You have already chosen this!" << endl;
						retry = 1;
					}
					break;
				case 3:
					if(s->getThrees() == 0)
						s->UpperScores(*h,3);
					else
					{
						cout << "You have already chosen this!" << endl;
						retry = 1;
					}
					break;
				case 4:
					if(s->getFours() == 0)
						s->UpperScores(*h,4);
					else
					{
						cout << "You have already chosen this!" << endl;
						retry = 1;
					}
					break;
				case 5:
					if(s->getFives() == 0)
						s->UpperScores(*h,5);
					else
					{
						cout << "You have already chosen this!" << endl;
						retry = 1;
					}
					break;
				case 6:
					if(s->getSixes() == 0)
						s->UpperScores(*h,6);
					else
					{
						cout << "You have already chosen this!" << endl;
						retry = 1;
					}
					break;
				default:
						retry = 1;
				}
			}
			else if (chooseUpLow == 2) 
			{
				cout << "Choose a sub category 1-7 as listed above: " << endl;
				cin >> chooseSubCat;
				switch (chooseSubCat) 
				{
				case 1: 
					if(s->getThreeOfAKinds() == 0)
						s->ThreeOfAKind(*h);
					else
					{
						cout << "You have already chosen this!" << endl;
						retry = 1;
					}
					break;
				case 2:
					if(s->getFourOfAKinds() == 0)
						s->FourOfAKind(*h);
					else
					{
						cout << "You have already chosen this!" << endl;
						retry = 1;
					}
					break;
				case 3:
					if(s->getSmallStraights() == 0)
						s->SmallStraight(*h);
					else
					{
						cout << "You have already chosen this!" << endl;
						retry = 1;
					}
					break;
				case 4:
					if(s->getLargeStraights() == 0)
						s->LargeStraight(*h);
					else
					{
						cout << "You have already chosen this!" << endl;
						retry = 1;
					}
					break;
				case 5:
					if(s->getFullHouses() == 0)
						s->FullHouse(*h);
					else
					{
						cout << "You have already chosen this!" << endl;
						retry = 1;
					}
					break;
				case 6:
					if(s->getYhatzees() == 0)
						s->Yhatzee(*h);
					else
					{
						cout << "You have already chosen this!" << endl;
						retry = 1;
					}
					break;
				case 7:
					if(s->getChances() == 0)
						s->Chance(*h);
					else
					{
						cout << "You have already chosen this!"<< endl;
						retry = 1;
					}
					break;
				default:
						retry = 1;
				}
			}
			else
			{
				cout << "INVALID INPUT" << endl;
				retry = 1;
			}
		}
		while (retry == 1);
		delete h;
	}
	cout << endl;
	cout << "Final score is: " << s->getTotalScore() << endl;

	ofstream fout;
	fout.open("High_Scores");
	if (fout.fail())
		cout << "Can't save score" << endl;
	else
		fout << s->getTotalScore() << endl;

	delete s;

	return 0;
}
