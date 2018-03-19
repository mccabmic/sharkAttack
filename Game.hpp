#ifndef GAME_HPP
#define GAME_HPP

#include "Item.hpp"
#include "Player.hpp"
#include "Space.hpp"
#include "HealRoom.hpp"
#include "NormalRoom.hpp"
#include "TrapRoom.hpp"
#include "WinningRoom.hpp"
#include <sstream>

using std::endl;
using std::cin;
using std::cout;

class Game {

protected:
	Player& player;

	// Map - 6 
	Space* mySpace = new HealRoom();
	Space* myOtherSpace = new NormalRoom();
	Space* mySouthSpace = new TrapRoom();
	Space* myExtraSouthSpace = new WinningRoom();
	Space* myNorthSpace = new NormalRoom();
	Space* oneMoreSpace = new TrapRoom("This room is very dark. You cannot see anything.");
	
public:
	Space* currentLocation;

	Game(Player& newPlayer) : player(newPlayer){ init(); }
	~Game();

	void init();
	void handle_pickup();
	bool movePlayer(DIRECTION myDirection);
	void handle_interaction();
	void handle_inventory();
	void look();

	void displayPrompts();
	bool winState();

	// Menu items
	int getInt(const std::string prompt);


};
#endif // !GAME_HPP
