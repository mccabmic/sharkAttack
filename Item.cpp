#include "Item.hpp"

void wallet::addToWallet(item& thisItem) {
	if (items.size() >= capacity) {
		return;
	}
	else {
		items.push_back(thisItem);
	}
}
bool wallet::search(item myThing) {

	std::vector<item>::iterator it;

	it = std::find(items.begin(), items.end(), myThing);

	if (it != items.end()) {
		return true;
	}

	else {
		return false;
	}
}

std::string wallet::printContents() {
	std::string returnString = "";

	if (!isEmpty()) {
		for (auto i : items) {
			returnString += i.description + " ";
		}
	}
	else
		returnString += "nothing";

	return returnString;
}

item wallet::removefromWallet() {
	item temp= items[items.size() - 1];
	items.pop_back();

	return temp;
}

item wallet::removefromWallet(int index) {
	item temp = items[index];
	items.erase(items.begin() + index);
	return temp;
}

void wallet::grab(int index, wallet& otherGuy) {
	if (otherGuy.isEmpty()) {
		return;
	}
	item temp = otherGuy.removefromWallet(index);
	addToWallet(temp);

}

void wallet::grab(wallet& otherGuy) {
	if (otherGuy.isEmpty()) {
		return;
	}
	item temp = otherGuy.removefromWallet();
	addToWallet(temp);
}