#include "WinningRoom.hpp"

void WinningRoom::interact(Player& player) {
	if (player.Inventory.search(winningStaff)) {
		player.setWin();
	}

	else {
		std::cout << "You don't seem to have the required item." << std::endl;
	}
}
