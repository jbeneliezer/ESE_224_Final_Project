#pragma once
#include "basicFunctions.h"

class Account {
protected:
	string username, password;
public:
	Account();
	Account(string, string);
};