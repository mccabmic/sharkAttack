#include <iostream>
#include "item.hpp"
#include "Space.hpp"
#include "Player.hpp"

using namespace std;

int main() {

	item myStaff;
	myStaff.description = "A cracked staff";
	myStaff.ezID = "A staff";

	Space mySpace("Start room", "This room is your starting location. Say hello!");
	Space myOtherSpace("A different room", "this room smells like wet dogs and awful people");

	// Set these fuckers
	mySpace.left = &myOtherSpace;
	myOtherSpace.right = &mySpace;

	Player p(&mySpace);
	
	myOtherSpace.roomContents.addToWallet(myStaff);

	cout << "Player looking inside its current location" << endl;
	cout << p.look() << endl;

	cout << "Player looking left from mySpace:" << endl;
	cout << p.look(mySpace.left) << endl;

	cout << "Player looking right from mySpace:" << endl;
	cout << p.look(mySpace.right) << endl;

	cout << "Changing rooms" << endl;
	p.move(mySpace.up);

	cout << "Player looking inside its current location" << endl;
	cout << p.look() << endl;

	cout << "Player looking left from mySpace:" << endl;
	cout << p.look(mySpace.left) << endl;

	cout << "Player looking right from mySpace:" << endl;
	cout << p.look(mySpace.right) << endl;





	cin.get();
	return 0;
}

