#ifndef TRAPROOM_HPP
#define TRAPROOM_HPP

#include "Space.hpp"
class TrapRoom : public Space{

public:
	TrapRoom(std::string description) : Space(description) {}
	TrapRoom() : Space("This seems like an ordinary room. There are thorns and barbs around many of the rusted weapons around here.") {}
	virtual ~TrapRoom() {}

	void interact(Player& Player);

};

#endif // TRAPROOM_HPP
