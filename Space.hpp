#ifndef SPACE_HPP
#define SPACE_HPP

#include "Item.hpp"


class Space {
public:

	// directions
	Space* left = nullptr;
	Space* right = nullptr;
	Space* up = nullptr;
	Space* down = nullptr;

	wallet roomContents = wallet(20);
	std::string quicklook;
	std::string longlook;

public:
	void printExits();
	std::string shortDescription();
	std::string longDescription();
	Space() : quicklook("An empty room"), longlook("A developer was lazy and found a way to isntantiate this shit") {}
	Space(std::string mydescription, std::string myLongdescription) : quicklook(mydescription), longlook(myLongdescription) {}

};

#endif // !SPACE_HPP
