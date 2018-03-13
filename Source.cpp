#include <iostream>
#include "item.hpp"

using namespace std;

int main() {

	// Dummy ID
	item shield;
	shield.ezID = "shield";

	// Sword Full ID
	item sword;
	sword.ezID = "sword";
	sword.description = "a rusty sword";
	sword.longDescription = "This blade's shimmer has been dulled after years of use. It is chipped and rusted.";

	// Staff Full ID
	item staff;
	staff.ezID = "staff";
	staff.description = "a cracked staff";
	staff.longDescription = "The cracked and gnarled wood on this staff looks infected.";
	
	// Construct a wallet of size 10
	wallet myStuff = wallet(10);
	
	myStuff.addToWallet(sword);
	myStuff.addToWallet(staff);
	
	cout << "Items added to wallet" << endl;
	cout << "Testing search:";
	myStuff.search(sword);
	myStuff.search(shield);

	cout << "My contents: ";
	myStuff.printContents();

	wallet hisStuff = wallet();

	cout << "His contents: ";
	hisStuff.printContents();

	cout << "He attempts to steal...";
	hisStuff.grab(sword, myStuff);

	cout << "My contents: ";
	myStuff.printContents();
	myStuff.search(sword);

	cout << "His contents: ";
	hisStuff.printContents();

	cout << "He attempts to steal...";
	hisStuff.grab(sword, myStuff);

	cout << "My contents: ";
	myStuff.printContents();
	myStuff.search(sword);

	cout << "His contents: ";
	hisStuff.printContents();

	cout << "He attempts to steal...";
	hisStuff.grab(sword, myStuff);

	cout << "My contents: ";
	myStuff.search(sword);
	myStuff.printContents();

	cout << "His contents: ";
	hisStuff.printContents();

	cin.get();
	return 0;
}