#include "user.h"

User::User() : Account(), real(false), wins(0), losses(0), streak(0) {}

User::User(string u, string p) : Account(u, p), real(true), wins(0), losses(0), streak(0), last_play("emptyWord") {}

User::User(string u, string p, string last, int s, int w, int l, double per) : Account(u, p) {
	streak = s;
	last_play = last;
	wins = w;
	losses = l;
	percentage = per;
}

bool User::isReal() { return real; }

string User::getUsername() { return username; }

string User::getPassword() { return password; }

int User::getWins() { return wins; }

int User::getLosses() { return losses; }

double User::getPct() { return percentage; }

int User::getStreak() { return streak; }

string User::getLast() { return last_play; }

void User::setLast(string s) {
	last_play = s;
}

void User::inc(bool b) {
	if (b) {
		++wins;
		streak = (streak > 0) ? streak + 1 : 1;
	}
	else {
		++losses;
		streak = (streak < 0) ? streak - 1 : -1;
	}
	percentage = 100 * (wins / ((double) wins + (double) losses));
}

User User::login(vector<User> v, int tries) {
	while (tries > 0) {
		string u, p;
		cout << "Enter username: ";
		cin >> u;

		for (auto& i : v) {
			if (u.compare(i.getUsername()) == 0) {
				cout << "Enter password: ";
				cin >> p;
				if (p.compare(i.getPassword()) == 0) return i;
				else return User();
			}
		}
		cout << "Incorrect username or password" << endl;
		--tries;
	}
	return User();
}

void User::print() {
	cout << setw(10) << "Name" << setw(10) << "Wins" << setw(10) << "Losses" << setw(10) << "WinPct" << setw(10) <<
		"WinStreak" << setw(10) << "LastPlay" << endl;

	char pct[10];
	sprintf_s(pct, 10, "%.2f %%", percentage);

	cout << noshowpos << setw(10) << username << setw(10) << wins << setw(10) << losses << setw(10) << pct 
		<< setw(10);
	cout << showpos << streak << setw(10) << last_play << endl;
	system("pause");
}

vector<User> scanUsers(string filename) {
	vector<User> lst;
	ifstream file(filename);
	string first;
	string name, pass, last;
	int w, l, _streak;
	double percent;
	getline(file, first).ignore();
	string line, s;
	char p;

	while (getline(file, line)) {
		istringstream ss(line);
		ss >> name >> pass >> w >> l >> percent >> p >> _streak >> last;
		// cout << name << " "<< pass << " " << w << " " << l << " " << percent << p << " " << _streak << " " << last << endl;
		lst.push_back(User(name, pass, last, _streak, w, l, percent));
	}
	return lst;
}

void User::menu() {
	system("cls");
	printMessage("Hello " + username, true, false);
	printMessage("1. Play game", true, false);
	printMessage("2. Check your history", false, true);
}

int User::actionSelect() {
	char action;
	cout << "Please select a number to continue, enter q to quit: ";
	cin >> action;
	if (action == 'q') { system("cls"); return 0; }
	else if (action == '1') return 1;
	else if (action == '2') return 2;
	else if (action == '3') return 3;
	else menu();
	cout << "Invalid entry" << endl;
	actionSelect();
}

bool User::operator== (User u) {
	return (username == u.getUsername() && password == u.getPassword());
}