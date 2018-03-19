#include "Game.hpp"

Game::~Game() {

	if (mySpace != nullptr) delete mySpace;
	if (myOtherSpace != nullptr) delete myOtherSpace;
	if (mySouthSpace != nullptr) delete mySouthSpace;
	if (myExtraSouthSpace != nullptr) delete myExtraSouthSpace;
	if (myNorthSpace != nullptr) delete myNorthSpace;
	if (oneMoreSpace != nullptr) delete oneMoreSpace;

}

bool Game::winState() {
	if (player.getWin()) {
		cout << "With a satisfying click, the staff slides into the hole." << endl;
		cout << "A soft rumble quakes below your feet as you hear ancient mechanicsms groaning after being awakened" << endl;
		cout << "after years of neglect.  One of the walls in the rooms now  shivers." << endl;
		cout << "The faint smell of fresh air and a creak of daylight brightens the room and your spirit." << endl;
		cout << "You leave victorious!" << endl;
		return false;
	}

	else if (player.returnHP() < 0) {
		cout << "You have succumbed to boredom. Game Over." << endl;
		return false;
	}

	else {
		return true;
	}
}
void Game::init() {
	
	item myStaff;
	myStaff.description = "A cracked staff";
	myStaff.ezID = "A staff";

	item sword;
	sword.ezID = "sword";
	sword.description = "a rusty sword";
	sword.longDescription = "This blade's shimmer has been dulled after years of use. It is chipped and rusted.";


	// Link the exits
	mySpace->down = mySouthSpace;
	mySouthSpace->up = mySpace;

	mySpace->up = myNorthSpace;
	myNorthSpace->down = mySpace;
	
	mySpace->right = myOtherSpace;
	myOtherSpace->left = mySpace;

	mySpace->left = oneMoreSpace;
	oneMoreSpace->right = mySpace;

	mySouthSpace->down = myExtraSouthSpace;
	myExtraSouthSpace->up = mySouthSpace;

	// Add items to rooms
	myOtherSpace->roomContents.addToWallet(sword);
	myOtherSpace->roomContents.addToWallet(myStaff);

	// Downcast winning room
	WinningRoom& newWinningRoom = dynamic_cast<WinningRoom&>(*myExtraSouthSpace);
	newWinningRoom.setWinningItem(myStaff);
	
	// Set mySpace to be current location
	currentLocation = mySpace;

	// Start title crawl
	displayPrompts();
	
	cout << "The game begins with you being lost in an old temple, or something." << endl;
	cout << "The goal is to find an item and use that item in a place so you can get out." << endl;
	cout << currentLocation->longDescription() << endl;

}

void Game::displayPrompts() {
	cout << "---------Instructions----------" << endl;
	cout << "[8] moves north" << endl;
	cout << "[2] moves south" << endl;
	cout << "[4] moves west" << endl;
	cout << "[6] moves east" << endl;

	cout << "[i] is for inventory ";
	cout << "[e] is to interact" << endl;

	cout << "[p] is to pickup ";
	cout << "[l] looks for exits" << endl;

	cout << "[h] displays this menu" << endl;
	cout << "[q] quits the game" << endl;
	cout << "-------------------------------" << endl;

}
bool Game::movePlayer(DIRECTION myDirection) {
	
	if (myDirection == north) {
		if (currentLocation->up != nullptr) {
			currentLocation = currentLocation->up;
			player.takeDamage(1);
			cout << currentLocation->longDescription() << endl;
			return true;
		}
	}

	if (myDirection == east) {
		if (currentLocation->right != nullptr) {
			currentLocation = currentLocation->right;
			player.takeDamage(1);
			cout << currentLocation->longDescription() << endl;
			return true;
		}
	}

	if (myDirection == south) {
		if (currentLocation->down != nullptr) {
			currentLocation = currentLocation->down;
			player.takeDamage(1);
			cout << currentLocation->longDescription() << endl;
			return true;
		}
	}

	if (myDirection == west) {
		if (currentLocation->left != nullptr) {
			currentLocation = currentLocation->left;
			player.takeDamage(1);
			cout << currentLocation->longDescription() << endl;
			return true;
		}
	}

	// All else fails
	return false;
}

void Game::handle_interaction() {
	currentLocation->interact(player);
}

void Game::handle_pickup() {
	if (currentLocation->roomContents.isEmpty()) {
		cout << "You see nothing to pickup here." << endl;
		return;
	}

	else if (currentLocation->roomContents.size() == 1) {
		player.Inventory.grab(currentLocation->roomContents);
		cout << "You pick up the item" << endl;
		cout << "You are now carrying: " << player.Inventory.printContents() << endl;
	}

	else {
		int input;

		input = getInt("Which would you like to grab (use 0, 1, etc): ");
		while (input > currentLocation->roomContents.size() - 1) {
			input = getInt("That doesn't exist!");
		}

		player.Inventory.grab(input, currentLocation->roomContents);
		cout << "You pick up the item" << endl;
		cout << "You are now carrying: " << player.Inventory.printContents() << endl;
	}
}

void Game::look() {
	
	cout << currentLocation->longDescription() << endl;
	cout << "You inspect the exits:" << endl;

	cout << "To the north is: ";
	if (currentLocation->up == nullptr) {
		cout << "a wall." << endl;
	}
	else {
		cout << "an open space." << endl;
	}

	cout << "To the south is: ";
	if (currentLocation->down == nullptr) {
		cout << "a wall." << endl;
	}

	else {
		cout << "an open space." << endl;
	}

	cout << "To the east is: ";
	if (currentLocation->right == nullptr) {
		cout << "a wall." << endl;
	}
	
	else {
		cout << "an open space." << endl;
	}

	cout << "To the west is: ";
	if (currentLocation->left == nullptr) {
		cout << "a wall." << endl;
	}

	else {
		cout << "an open space." << endl;
	}

	//currentLocation->printExits();
}

void Game::handle_inventory() {
	cout << "You are carrying: " << player.Inventory.printContents() << endl;
}

int Game::getInt(const std::string prompt) {
	int integer;
	std::string input;

	bool isValid = true;

	do {
		std::cout << prompt;
		std::getline(std::cin, input);

		// Loop through all characters and determine if they are a digit or not
		for (unsigned i = 0; i < input.length(); i++) {
			if (!isdigit(input[i])) {
				std::cout << "Invalid input" << std::endl;
				isValid = false;
				cin.clear();
				break;
			}

			else {
				isValid = true;
			}
		}
	} while (isValid == false);

	// After scrubbing, cast the input into an integer
	std::stringstream ss(input);

	ss >> integer;

	return integer;
}
