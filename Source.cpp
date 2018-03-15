#include <iostream>
#include "item.hpp"
#include "Space.hpp"


std::string look(Space*);

using namespace std;

int main() {

	item myStaff;
	myStaff.description = "A cracked staff";
	myStaff.ezID = "A staff";

	Space mySpace;
	Space myOtherSpace("A different room", "this room smells like wet dogs and awful people");

	// Set these fuckers
	mySpace.left = &myOtherSpace;
	myOtherSpace.right = &mySpace;

	//Right now, picture a top down view where you can see literally all the rooms
	cout << look(mySpace.left) << endl;
	cout << look(mySpace.right) << endl;

	// This will probably need to be a function as part of the mapbuilding
	myOtherSpace.roomContents.addToWallet(myStaff);

	cout << look(mySpace.left) << endl;
	cout << look(mySpace.right) << endl;

	cin.get();
	return 0;
}

std::string look(Space* location) {

	if (location == nullptr)
		return ("You see a cold hard wall");
	else {
		return location->longDescription();
	}
}

