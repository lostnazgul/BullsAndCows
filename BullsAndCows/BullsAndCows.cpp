// BullsAndCows.cpp : simple game
//

#include "pch.h"
#include <vector>
#include <iostream>
#include <string>
#include <random>

using namespace std;

const string prompt = "> ";

random_device rd;     // only used once to initialise (seed) engine
mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
uniform_int_distribution<int> uni(0, 9); // guaranteed unbiased

vector<int> vect; // to save guess numbers
vector<int> u_vect; // to save user input

int main()
{
	while (true) {
		// Init hidden numbers
		for (int i = 0; i <= 3; i++) {		
			auto random_integer = uni(rng);
			vect.push_back(random_integer);
		}
		// Game start
		bool game = true;
		while (game) {
			int bulls, cows;
			bulls = cows = 0;
			u_vect.clear();
			cout << "Please enter 4 numbers 0-9\n";
			cout << prompt;
			char ch;
			// get user input
			for (int i = 0; i <= 3; i++) {
				cin >> ch;
				if (isdigit(ch)) {
					u_vect.push_back(ch - '0');
				}
			}			
			// check numbers
			for (int i = 0; i < vect.size(); i++) {
				if (vect[i] == u_vect[i]) bulls++;
				else {
					for (int j = 0; j < vect.size(); j++) {
						if (vect[i] == u_vect[j]) cows++;
					}
				}
			}
			// Game end
			cout << "Bulls = " << bulls << ", and cows = " << cows << endl << endl;
			if (bulls == 4 and cows == 0) {
				game = false;
				bulls = cows = 0;
				u_vect.clear();
				vect.clear();
				cout << "\nYou win! Thank's for game.\n";
			}
		}
	}
}