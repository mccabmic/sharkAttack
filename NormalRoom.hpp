#ifndef NORMALROOM_HPP
#define NORMALROOM_HPP

#include "Space.hpp"

class NormalRoom : public Space {

public:
	NormalRoom() : Space("This appears to be an ordinary room, covered with murals and scratch marks") {}
	NormalRoom(std::string customDescription) : Space(customDescription) {}
	virtual ~NormalRoom() {}

	void interact(Player& Player);

};

#endif // !NORMALROOM_HPP
