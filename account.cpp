#include <iostream>
#include <string>
#include "account.h"

using namespace std;

Account::Account() {}

Account::Account(string u, string p) : username(u), password(p) {}
