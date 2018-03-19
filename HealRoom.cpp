#include "HealRoom.hpp"

void HealRoom::interact(Player& player) {
	std::cout << "You feel yourself refreshed." << std::endl;
	player.heal(2);
}