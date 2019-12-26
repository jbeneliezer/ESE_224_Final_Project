#pragma once
#include "basicFunctions.h"
#include "user.h"

class Game{
private:
	User user;
	bool complete;
	char letter;
	int num_guesses, num_misses;
	string word_secret, word_current, guesses, misses, rope, head, torso, legs;
public:
	Game();
	Game(User);
	void next();
	void printMan();
	void start();
	void play();
	void finish();
	void record(User&, vector<User>&);
};
