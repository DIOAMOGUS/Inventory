#include <iostream>
#include <string>
#include <vector>

#include "box.hpp"

// #define DEBUG

Box::Box(short boxID, std::string_view stuff)
		: m_boxID { boxID }
		, m_stuff { stuff }
{
	std::cout << "Successfully constructed the box.\n";
#ifdef DEBUG
	std::cout << "Box ID: " << m_boxID << '\n'
	<< "Box Stuff: " << m_stuff << '\n';
#endif
}

int Box::findBox(const std::vector<Box>& vboxes, short desiredboxID) const
{
	for (size_t i = 1; i < vboxes.size(); ++i) {
		if (desiredboxID == vboxes[i].m_boxID) {
			return i;
		}
	}
	return -1;
}

void Box::createBox(std::vector<Box>& vboxes, short desiredBoxID)
{
	std::cout << "What will you store in your box?\n";
	std::string stuff{};
	std::getline(std::cin >> std::ws, stuff);

	Box* b = new Box(desiredBoxID, stuff);
	vboxes.emplace_back(*b);
	delete b;
}

void Box::printBox(const std::vector<Box>& vboxes, short indexOfBox) const
{
	std::cout << "This box contains: \n" << vboxes[indexOfBox].m_stuff << '\n';
}

void Box::editBox(std::vector<Box>& vboxes, short indexOfBox)
{
	std::cout << "EDIT IT\n";
	std::string stuff{};
	std::getline(std::cin >> std::ws, stuff);
	vboxes[indexOfBox].m_stuff = stuff;
	std::cout << "Successfully edited the box.\n";
}

void Box::listBoxes(const std::vector<Box>& vboxes) const
{
	for (size_t i = 1; i < vboxes.size(); ++i) {
		std::cout << "Box " << vboxes[i].m_boxID << ":\nThis box contains: \n" << vboxes[i].m_stuff << '\n';
	}
#ifdef DEBUG
	std::cout << "size of vector = " << vboxes.size() << '\n';
#endif
}

void Box::deleteBox(std::vector<Box>& vboxes, short indexOfBox)
{
	vboxes.erase(vboxes.begin() + indexOfBox);
	std::cout << "Successfully destroyed the box.\n";
}
