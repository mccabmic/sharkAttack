#ifndef HEALROOM_HPP
#define HEALROOM_HPP

#include "Space.hpp"
class HealRoom :public Space{

public:
	HealRoom(std::string customDescription) : Space(customDescription) {}
	HealRoom(): Space("The sound of a soft trickle draws your attention to a fountain in the middle \nof the room.Perhaps you can drink from it."){}
	virtual ~HealRoom() {}

	void interact(Player& Player);

};

#endif // !HEALROOM_HPP
