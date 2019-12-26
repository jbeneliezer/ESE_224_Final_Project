#pragma once
#include "account.h"

class User : public Account {
private:
	bool real;
	int wins, losses, streak;
	double percentage = 0;
	string last_play;
public:
	User();
	User(string, string);
	User(string, string, string, int, int, int, double);
	bool isReal();
	User login(vector<User>, int);
	string getUsername();
	string getPassword();
	int getWins();
	int getLosses();
	double getPct();
	int getStreak();
	string getLast();
	void inc(bool);
	void setLast(string);
	void print();
	void menu();
	int actionSelect();
	bool operator== (User u);
};

vector<User> scanUsers(string);
