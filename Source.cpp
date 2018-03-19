#include <iostream>
#include "Game.hpp"

using std::string;


int main() {

	// Make player and keep track of player's location
	Player user(10);
	Game myGame(user);

	// Handle input
	string input;
	
	// end game when player's dead, game will tell me when
	do{
		cout << "Time left: " << user.returnHP() << " steps" << endl;
		cout << "Enter a command : ";
		getline(cin, input);
		
		// Go north
		if (input == "8") {
			if (!myGame.movePlayer(north)) {
				cout << "You go nowhere. Try 'l' to look around. " << endl;
			}
		}

		// Go south
		else if (input == "2") {
			if (!myGame.movePlayer(south)) {
				cout << "You go nowhere. Try 'l' to look around. " << endl;
			}
		}

		// Go west
		else if (input == "4") {
			if (!myGame.movePlayer(west)) {
				cout << "You go nowhere. Try 'l' to look around. " << endl;
			}
		}

		// Go east
		else if (input == "6") {
			if (!myGame.movePlayer(east)) {
				cout << "You go nowhere. Try 'l' to look around. " << endl;
			}
		}

		// Interact with room
		else if (input == "e") {
			myGame.handle_interaction();
		}

		// Pickup items
		else if (input == "p") {
			myGame.handle_pickup();
		}

		// Look around
		else if (input == "l") {
			myGame.look();
		}
		
		// Check inventory
		else if (input == "i") {
			myGame.handle_inventory();
		}

		else if (input == "h") {
			myGame.displayPrompts();
		}

		else if (input == "q") {
			cout << "Quitting..." << endl;
			break;
		}

		else {
			cout << "Unsupported command" << endl;
			myGame.displayPrompts();
		}

	} while (myGame.winState());


	cin.get();
	return 0;
}
