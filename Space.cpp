#include "Space.hpp"

void Space::printExits() {
	std::cout << "This: " << this << std::endl;
	std::cout << "Left: " << left << std::endl;
	std::cout << "Right: " << right << std::endl;
	std::cout << "Up: " << up << std::endl;
	std::cout << "Down: " << down << std::endl;
}

std::string Space::shortDescription() {
	std::string returnString = "";

	returnString += quicklook;

	if (roomContents.isEmpty()) {
		returnString += "\nYou see nothing of value";
	}
	else {
		returnString += "\nYou see: " + roomContents.printContents();
	}
	return returnString;
}

std::string Space::longDescription() {
	std::string returnString = "";

	returnString += longlook;

	if (roomContents.isEmpty()) {
		returnString += "\nYou see nothing of value";
	}
	else {
		returnString += "\nYou see: " + roomContents.printContents();
	}
	return returnString;
}