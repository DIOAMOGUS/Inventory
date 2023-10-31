#include <iostream>
#include <string>
#include <vector>

#include "box.hpp"

// #define DEBUG

Box::Box(int boxID, std::string_view stuff)
		: m_boxID { boxID }
		, m_stuff { stuff }
{
	std::cout << "Successfully constructed the box.\nBox ID: " << m_boxID << '\n';
#ifdef DEBUG
	std::cout << "box stuff: \n" << m_boxID << '\n' << m_stuff << '\n' << m_inUse << '\n';
#endif
}

int Box::findBox(const std::vector<Box>& vboxes, const int& desiredboxID) const
{
	for (size_t i = 1; i < vboxes.size(); ++i) {
		if (desiredboxID == vboxes[i].m_boxID) {
			return vboxes[i].m_boxID;
		}
	}
	std::cerr << "Error! No box found!\n";
	return -1;
}

void Box::createBox(std::vector<Box>& vboxes, int& lastCreatedBoxID)
{
	std::cout << "What will you store in your box?\n";
	std::string stuff{};
	std::getline(std::cin >> std::ws, stuff);

	Box* b = new Box(lastCreatedBoxID, stuff);
	vboxes.emplace_back(*b);
	delete b;
	++lastCreatedBoxID;
}

void Box::printBox(const std::vector<Box>& vboxes, const int& desiredBoxID) const
{
	std::cout << "This box contains: \n" << vboxes[desiredBoxID].m_stuff << '\n';
}

void Box::editBox(std::vector<Box>& vboxes, const int& desiredBoxID)
{
	std::cout << "EDIT IT\n";
	std::string stuff{};
	std::getline(std::cin >> std::ws, stuff);
	vboxes[desiredBoxID].m_stuff = stuff;
	std::cout << "Successfully edited the box.\n";
}

void Box::listBoxes(const std::vector<Box>& vboxes) const
{
	for (size_t i = 1; i < vboxes.size(); ++i) {
		std::cout << "Box " << i << ":\nThis box contains: \n" << vboxes[i].m_stuff << '\n';
	}
#ifdef DEBUG
	std::cout << "size of vector = " << vboxes.size() << '\n';
#endif
}

void Box::deleteLastBox(std::vector<Box>& vboxes, int& lastCreatedBoxID)
{
	vboxes.pop_back();
	--lastCreatedBoxID;
	std::cout << "Successfully destroyed the box.\n";
}
