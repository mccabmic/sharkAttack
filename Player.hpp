#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Space.hpp"

enum DIRECTION {up = 1, right, down, left};

class Player {
private:
	int hp;
	Space* currentLocation;
	wallet Inventory = wallet(5);

public:
	Player(Space* whereIam) : hp(15), currentLocation(whereIam) {}
	std::string  interact() { return "I am dumb"; }
	std::string look(Space* location);
	std::string look();

	void move(Space* location) { currentLocation = location; }
};
#endif // !PLAYER_HPP
