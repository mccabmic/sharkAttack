#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Item.hpp"

class Player {
private:
	int hp;
	bool win = false;

public:
	wallet Inventory = wallet(5);	
	Player(int hp): hp(hp){}
	void takeDamage(int damage);
	int returnHP() { return hp; }
	void heal(int healPoints) {
		hp += healPoints;
	}

	void setWin() { win = true; }
	bool getWin() { return win; }
};
#endif // !PLAYER_HPP
