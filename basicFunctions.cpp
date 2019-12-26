#include "basicFunctions.h"

// prints message centered in box, top and bottom can be removed
void printMessage(string message, bool printTop = true, bool printBottom = true)
{
	if (printTop) {
		cout << "+---------------------------------+" << endl;
		cout << "|";
	}
	else {
		cout << "|";
	}

	bool front = true;

	for (size_t i = message.length(); i < 33; i++) {
		if (front) {
			message = " " + message;
		}
		else {
			message = message + " ";
		}
		front = !front;
	}
	cout << message.c_str();

	if (printBottom) {
		cout << "|" << endl;
		cout << "+---------------------------------+" << endl;
	}
	else {
		cout << "|" << endl;
	}
}

// picks and returns a random string specified file 
string loadRandomWord(string path)
{
	srand(time(0));
	string word;
	vector<string> v;
	ifstream file(path);
	if (file.is_open())
	{
		while (getline(file, word))
			v.push_back(word);
		word = v[rand() % v.size()];
		file.close();
	}
	return word;
}

// returns a double spaced version of entered string
string doubleSpace(string s) {
	string newString;
	for (char i: s) {
		newString += i;
		newString += ' ';
	}
	return newString;
}

// creates sign in page
void signin() {
	printMessage("Hangman Game", true, false);
	printMessage("ESE 224 Fall 2019", true, false);
	printMessage("Creator:", true, false);
	printMessage("Judah Ben-Eliezer", false, false);
	printMessage("1. Start a new game", true, false);
	printMessage("2. Sign in as user", false, false);
	printMessage("3. Sign in as admin", false, true);
}


// takes user input for desired action, repeats until valid input
int actionSelect() {
	char action;
	cout << "Please select a number to continue, enter q to quit: ";
	cin >> action;
	if (action == 'q') exit(0);
	else if (action == '1') return 1;
	else if (action == '2') return 2;
	else if (action == '3') return 3;
	else system("cls");
	signin();
	cout << "Invalid entry" << endl;
	actionSelect();
}
