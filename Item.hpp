#ifndef ITEMS_HPP
#define ITEMS_HPP

#include <string>
#include <vector>
#include <iostream>


struct item {
	
	std::string ezID;
	std::string description;
	std::string longDescription;
	int id = 0;

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
	void addToWallet(item& thisItem) { thisItem.id++; items.push_back(thisItem); } // use capactity to limit the wallet size
	void search(item myThing);
	item removefromWallet();

	bool isEmpty() { return items.size() == 0; }
	void grab(item thingIwant, wallet& otherGuy);

	std::string printContents();

	wallet() : capacity(10) {}
	wallet(int size) : capacity(size) {}

	virtual ~wallet() {}
};
#endif // !ITEMS_HPP
