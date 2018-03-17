#include "Player.hpp"


std::string Player::look(Space* mySpace) {
	if (mySpace == nullptr)
		return ("You see a dark wall");
	else
		return mySpace->shortDescription();
}

std::string Player::look() {

	if (currentLocation == nullptr)
		return ("You have been cast into oblivion");
	else
		return currentLocation->longDescription();

}