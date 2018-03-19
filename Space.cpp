#include "Space.hpp"

// Debugging
void Space::printExits() {
	std::cout << "This: " << this << std::endl;
	std::cout << "Left: " << left << std::endl;
	std::cout << "Right: " << right << std::endl;
	std::cout << "Up: " << up << std::endl;
	std::cout << "Down: " << down << std::endl;
}


std::string Space::longDescription() {
	std::string returnString = "";

	returnString += roomDescription;

	if (roomContents.isEmpty()) {
		returnString += "\nYou see no items of value anywhere";
	}
	else {
		returnString += "\nYou see: " + roomContents.printContents();
	}
	return returnString;
}
