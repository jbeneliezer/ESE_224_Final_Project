#pragma once
#include "account.h"

class Admin : public Account {
private:
	list<string> word_list;
public:
	Admin(string, string);
	void sort();
	void printWordList();
	void addWord(string);
	void deleteWord(string s);
	void menu();
	int actionSelect();
};

Admin init();
bool login(int);