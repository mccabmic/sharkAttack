#ifndef ITEMS_HPP
#define ITEMS_HPP

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


struct item {
	
	std::string ezID;
	std::string description;
	std::string longDescription;

	// Lets me use std::find
	bool operator==(const item& obj2) const {
		return (this->description == obj2.description);
	}
};

class wallet {
private:
	std::vector<item> items;
	int capacity; // will eventually cap stuff

public:
	void addToWallet(item& thisItem);
	bool search(item myThing);

	item removefromWallet();
	item removefromWallet(int index);

	bool isEmpty() { return items.size() == 0; }

	void grab(int index, wallet& otherGuy);
	void grab(wallet& otherGuy);

	int size() { return items.size(); }

	std::string printContents();

	wallet() : capacity(10) {}
	wallet(int size) : capacity(size) {}

	virtual ~wallet() {}
};
#endif // !ITEMS_HPP
