#include <iostream>
#include "game.h"

using namespace std;

Game::Game() : rope("|"), num_guesses(0), num_misses(0), complete(false), letter(NULL) {}

Game::Game(User u) : user(u), complete(false), rope("|"), num_guesses(0), num_misses(0), letter(NULL) {}

// prints game environment to the console
void Game::printMan() {
	printMessage("Hangman", true, false);
	printMessage(rope, true, false);
	printMessage(head, false, false);
	printMessage(torso, false, false);
	printMessage(legs, false, true);
	printMessage(doubleSpace(word_current), false, true);
}

// advances hangman to next stage, used when user character guess is wrong
void Game::next() {
	if (head == "") head = "O";
	else if (torso == "") torso = "|";
	else if (torso == "|") torso = "/| ";
	else if (torso == "/| ") torso = "/|\\";
	else if (legs == "") legs = "/  ";
	else if (legs == "/  ") {
		legs = "/ \\";
		complete = true;
	}
}

// sets up game environment, initializes word_secret and word_current
void Game::start() {
	system("cls");
	word_secret = loadRandomWord("Wordlist.txt");

	/* uncomment this block to see word_secret before game
	cout << "word is: " << word_secret << endl;
	system("pause");
	system("cls");*/

	for (char i : word_secret) word_current += '_';
	printMan();
}

void Game::play() {
	if ((word_current.compare(word_secret) == 0) || complete) return;
	cout << "guess a letter: ";
	cin >> letter;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (word_secret.find(letter) == string::npos) {
		if (misses.find(letter) == string::npos) {
			misses += letter;
			num_misses++;
			next();
		}
	}
	else {
		if (guesses.find(letter) == string::npos) {
			guesses += letter;
			num_guesses++;
		}
		for (int i = 0; i < word_secret.length(); i++) {
			if (word_secret[i] == letter) word_current[i] = letter;
		}
	}
	system("cls");
	printMan();
	cout << "Guesses: " << doubleSpace(guesses) << endl;
	cout << "Misses: " << doubleSpace(misses) << endl;
	play();
}

// finishes game and prints final results
void Game::finish() {
	system("cls");
	printMan();
	cout << "Guesses: " << doubleSpace(guesses) << endl;
	cout << "Misses: " << doubleSpace(misses) << endl;
	cout << ((complete) ? "You lost, better luck next time." : "You won, congratulations!") << endl;
	system("pause");
	system("cls");
}

void Game::record(User& u, vector<User>& v) {
	u.inc(!complete);
	u.setLast(word_secret);
	vector<User>::iterator i = v.begin();
	while (i != v.end()) {
		if (*i == u) {
			v[i - v.begin()] = u;
			break;
		}
		++i;
	}
	ofstream file("UserAccountHistory.txt");
	if (file.is_open()) {
		file << setw(10) << "Name" << setw(10) << "Password" << setw(10) << "Wins" << setw(10) << "Losses" << setw(10) << "WinPct" << setw(10) <<
			"WinStreak" << setw(10) << "LastPlay" << endl;
		for (auto& i : v) {
			char pct[10];
			sprintf_s(pct, 10, "%.2f %%", i.getPct());
			file << noshowpos << setw(10) << i.getUsername() << setw(10) << i.getPassword() << setw(10) << i.getWins() << setw(10) << i.getLosses() << setw(10) << pct << setw(10);
			file << showpos << i.getStreak() << setw(10) << i.getLast() << endl;
		}
	}
}