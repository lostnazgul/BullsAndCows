// BullsAndCows.cpp : simple game
//

#include "pch.h"
#include <vector>
#include <iostream>

using namespace std;

inline int randint(int max) { return rand() % max; }

int main()
{
	vector<int> vect;
	int input, n, bulls, cows;
	bool game;
	while (true) {
		// Init hidden numbers
		vect.clear();
		cout << "\nEnter a begin(seed) number: ";
		cin >> n;
		for (int i = 0; i <= 3; i++) {
			srand(n + i);
			vect.push_back(randint(n));
		}
		// Init game
		game = true;
		while (game) {
			input = n = bulls = cows = 0;
			int degree = 1000;
			// Game start
			cout << "\nPlease enter 4 numbers 0-9 like(8435): ";
			cin >> input;
			for (int i = 0; i <= 3; i++) {
				if (input / degree % 10 == vect[i]) bulls++;
				else if (input / 100 % 10 == vect[i] || input / 10 % 10 == vect[i] || input % 10 == vect[i]) cows++;
				degree /= 10;
			}
			// Game end
			cout << "Bulls = " << bulls << ", and cows = " << cows << endl;
			if (bulls == 4 and cows == 0) {
				game = false;
				cout << "\nYou win! Thank's for game.\n";
			}
		}
	}
}
