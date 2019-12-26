#include <iostream>
#include "game.h"
#include "admin.h"

using namespace std;

int main() {

	int command;
	User user;
	vector<User> v = scanUsers("UserAccountHistory.txt");


	while(1) {
		// takes user to sign in page
		signin();

		// makes user choose action, repeats until valid command
		command = actionSelect();

		if (command == 1) {
			Game game;
			game.start();
			game.play();
			game.finish();
		}
		else if (command == 2) {
			User tmp = tmp.login(v, 5);
			system("cls");
			if (!tmp.isReal()) continue;
			else {
				user = tmp;
				user.menu();

				int userCommand = user.actionSelect();

				while (userCommand != 0) {
					if (userCommand == 1) {
						Game game(user);
						game.start();
						game.play();
						game.finish();
						game.record(user, v);
					}
					else if (userCommand == 2) {
						user.print();
					}

					user.menu();
					userCommand = user.actionSelect();
				}
			}
		}
		else if (command == 3) {
			if (!login(1)) continue;
			Admin admin = init();
			system("cls");
			admin.menu();
			int adminCommand = admin.actionSelect();

				while (adminCommand != 0) {
					if (adminCommand == 1) {
						admin.sort();
					}
					else if (adminCommand == 2) {
						string w;
						cout << "Enter word: ";
						cin >> w;
						admin.addWord(w);
					}
					else if (adminCommand == 3) {
						string w;
						cout << "Enter word: ";
						cin >> w;
						admin.deleteWord(w);
					}
					else if (adminCommand == 4) {
						admin.printWordList();
					}

					admin.menu();
					adminCommand = admin.actionSelect();
				}
		}
	}
}