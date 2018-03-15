#include "Item.hpp"

void wallet::search(item myThing) {

	// Just fuckin list an item with 1 2 3 4 5
	std::vector<item>::iterator it;

	it = std::find(items.begin(), items.end(), myThing);

	if (it != items.end()) {
		std::cout << it->longDescription << std::endl;
	}

	else {
		std::cout << "You turn out your pockets with a stupid look on your face." << std::endl;
	}
}

std::string wallet::printContents() {
	std::string returnString = "";

	if (!isEmpty()) {
		for (auto i : items) {
			returnString += i.description + " ";
		}
	}

	return returnString;
}

item wallet::removefromWallet() {
		
		// Can probably get this to remove specific thing in inventory
		item temp= items[items.size() - 1];
		items.pop_back();

		return temp;
}

void wallet::grab(item myThing, wallet& otherGuy) {

	// Everything will have a wallet
	if (otherGuy.isEmpty()) {
		std::cout << "There's nothing to grab" << std::endl;
		return;
	}

	std::cout << "Stole your shit!" << std::endl;
	addToWallet(otherGuy.removefromWallet());

}
