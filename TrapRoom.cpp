#include "TrapRoom.hpp"

void TrapRoom::interact(Player& player) {
	std::cout << "You try and wrestle with the barbs and the vines, but a giant spider " << std::endl;
	std::cout << "pops out and injures you! " << std::endl;
	player.takeDamage(5);
}