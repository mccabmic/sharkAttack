#ifndef WINNINGROOM_HPP
#define WINNINGROOM_HPP

#include "Space.hpp"

class WinningRoom: public Space {

private:
	item winningStaff;
	
public:
	WinningRoom() : Space("In the center of this room, there appears to be a small hole, big enough for\nperhaps a staff.") {}
	WinningRoom(std::string customDescription) : Space(customDescription) {}
	virtual ~WinningRoom() {}

	void interact(Player& Player);
	void setWinningItem(item item) { winningStaff = item; }

};

#endif // !WINNINGROOM_HPP
