#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "box.hpp"

// #define DEBUG

Box::Box(uint32_t boxID, std::string_view stuff)
	: m_boxID{ boxID }
	, m_stuff{ stuff }
{
	std::cout << "Successfully constructed the box.\n";
#ifdef DEBUG
	std::cout << "Box ID: " << m_boxID << '\n'
		<< "Box Stuff: " << m_stuff << '\n';
#endif
}

int Box::findBox(const std::vector<Box>& boxes, const uint32_t desiredboxID) const
{
	for (size_t i = 1; i < boxes.size(); ++i) {
		if (desiredboxID == boxes[i].m_boxID) {
			return i;
		}
	}
	return -1;
}

void Box::createBox(std::vector<Box>& boxes, const uint32_t desiredBoxID)
{
	std::cout << "What will you store in your box?\n";
	std::string stuff{};
	std::getline(std::cin >> std::ws, stuff);

	std::unique_ptr<Box> b = std::make_unique<Box>(desiredBoxID, stuff);
	boxes.emplace_back(*b);
}

void Box::printBox(const std::vector<Box>& boxes, const uint32_t indexOfBox) const
{
	std::cout << "This box contains: \n" << boxes[indexOfBox].m_stuff << '\n';
}

void Box::editBox(std::vector<Box>& boxes, const uint32_t indexOfBox)
{
	std::cout << "EDIT IT\n";
	std::string stuff{};
	std::getline(std::cin >> std::ws, stuff);
	boxes[indexOfBox].m_stuff = stuff;
	std::cout << "Successfully edited the box.\n";
}

void Box::listBoxes(const std::vector<Box>& boxes) const
{
	for (size_t i = 1; i < boxes.size(); ++i) {
		std::cout << "Box " << boxes[i].m_boxID << ":\nThis box contains: \n" << boxes[i].m_stuff << '\n';
	}
#ifdef DEBUG
	std::cout << "size of vector = " << boxes.size() << '\n';
#endif
}

void Box::deleteBox(std::vector<Box>& boxes, const uint32_t indexOfBox)
{
	boxes.erase(boxes.begin() + indexOfBox);
	std::cout << "Successfully destroyed the box.\n";
}
