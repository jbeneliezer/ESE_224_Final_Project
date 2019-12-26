#include "admin.h"

Admin init() {
	ifstream f("Admin.txt");
	if (f.is_open()) {
		string u, p;
		f >> u >> p;
		return Admin(u, p);
	}
}

Admin::Admin(string u, string p) : Account(u, p) {
	ifstream file("WordList.txt");
	if (file.is_open()) {
		string word;
		while (getline(file, word)) {
			word_list.push_back(word);
		}
	}
	else cout << "Cannot open wordlist" << endl;
}

bool login(int tries) {
	ifstream file("Admin.txt");
	string uname, u;
	string pass, p;
	if (file.is_open()) {
		file >> uname >> pass;
	}
	while (tries > 0) {
		cout << "Enter username: ";
		cin >> u;

		if (u.compare(uname) == 0) {
			cout << "Enter password: ";
			cin >> p;
			return (p.compare(pass) == 0);
		}
		cout << "Incorrect username or password" << endl;
		--tries;
	}
	return false;
}

void Admin::sort() { word_list.sort(); cout << "sorted" << endl; system("pause"); }

void Admin::printWordList() { for (auto& i : word_list) cout << i << endl; system("pause"); }

void Admin::addWord(string s) {
	list<string>::iterator it = find(word_list.begin(), word_list.end(), s);
	if (it != word_list.end()) {
		cout << "already on list" << endl;
	}
	else {
		word_list.push_back(s);
		ofstream file("Wordlist.txt");
		if (file.is_open()) {
			for (auto& i : word_list) {
				file << i << endl;
			}
			cout << "added" << endl;
		}
		else {
			cout << "cannot open wordlist" << endl;
			word_list.remove(s);
		}
		file.close();
	}
	system("pause");
}

void Admin::deleteWord(string s) {
	list<string>::iterator it = find(word_list.begin(), word_list.end(), s);
	if (it != word_list.end()) {
		word_list.remove(s);
		cout << "\'" << s << "\' removed" << endl;
	}
	else cout << "word not found!" << endl;
	system("pause");
}

void Admin::menu() { // prints admin menu
	system("cls");
	printMessage("Hello Admin", true, false);
	printMessage("1. Sort list alphabetically", true, false);
	printMessage("2. Add a word", false, false);
	printMessage("3. Delete a word", false, false);
	printMessage("4. Print word list", false, true);
}

int Admin::actionSelect() { // 
	char action;
	cout << "Please select a number to continue, enter q to quit: ";
	cin >> action;
	if (action == 'q') { system("cls"); return 0; }
	else if (action == '1') return 1;
	else if (action == '2') return 2;
	else if (action == '3') return 3;
	else if (action == '4') return 4;
	else menu();
	cout << "Invalid entry" << endl;
	actionSelect();
}
