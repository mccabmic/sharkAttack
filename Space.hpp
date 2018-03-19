#ifndef SPACE_HPP
#define SPACE_HPP

#include "Item.hpp"
#include "Player.hpp"
#include <string>

enum DIRECTION { north, east, south, west};

class Space {

protected:
	std::string roomDescription;

public:
	// directions
	Space* left = nullptr;
	Space* right = nullptr;
	Space* up = nullptr;
	Space* down = nullptr;
	
	wallet roomContents = wallet(20);
	
	void printExits();
	std::string longDescription();

	// Constructor destructor
	Space() : roomDescription("An empty room") {}
	Space(std::string mydescription) : roomDescription(mydescription) {}
	virtual ~Space() {}

	virtual void interact(Player& player) = 0;


};

#endif // !SPACE_HPP
