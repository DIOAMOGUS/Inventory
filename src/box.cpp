#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "box.hpp"
#include "functions.hpp"
#include "macros.hpp"

Box::Box(uint64_t boxID, std::string_view stuff)
	: m_boxID{ boxID }
	, m_stuff{ stuff }
{
	std::cout << "Successfully constructed the box.\n";
#ifdef DEBUG
	std::cout << "Box ID: " << m_boxID << '\n'
		<< "Box Stuff: " << m_stuff << '\n';
#endif
}

#ifdef DEBUG
Box::Box(const Box& box)
	: m_boxID{ box.m_boxID }
	, m_stuff{ box.m_stuff }
{
	std::cout << "Copy constructor called\n";
}
#endif

Box::~Box() {}

uint64_t findBox(std::vector<Box>& boxes, const uint64_t desiredboxID)
{
	for (uint64_t i = 0; i < boxes.size(); ++i) {
		if (desiredboxID == boxes[i].Box::getID()) {
			return i;
		}
	}
	return -1;
}

void createBox(std::vector<Box>& boxes, const uint64_t desiredBoxID)
{
	std::cout << "What will you store in your box?\n";
	std::string stuff{};
	std::getline(std::cin >> std::ws, stuff);

	std::unique_ptr<Box> b = std::make_unique<Box>(desiredBoxID, stuff);
	boxes.emplace_back(*b);
}

void printBox(std::vector<Box>& boxes, const uint64_t indexOfBox)
{
	std::cout << "This box contains: \n" << boxes[indexOfBox].Box::getStuff() << '\n';
}

void editBox(std::vector<Box>& boxes, const uint64_t indexOfBox)
{
	std::cout << "EDIT IT\n";
	std::string stuff{};
	std::getline(std::cin >> std::ws, stuff);
	boxes[indexOfBox].Box::setStuff(stuff);
	std::cout << "Successfully edited the box.\n";
}

void listBoxes(std::vector<Box>& boxes)
{
	for (uint64_t i = 0; i < boxes.size(); ++i) {
		std::cout << "Box " << boxes[i].Box::getID() << ":\nThis box contains: \n" << boxes[i].Box::getStuff() << '\n';
	}
#ifdef DEBUG
	std::cout << "size of vector = " << boxes.size() << '\n';
#endif
}

void deleteBox(std::vector<Box>& boxes, const uint64_t indexOfBox)
{
	boxes.erase(boxes.begin() + indexOfBox);
	std::cout << "Successfully destroyed the box.\n";
}

void deleteAllBoxes(std::vector<Box>& boxes)
{
	while (true) {
		std::cout << "Are you sure you want to clear everything? y/n\n";
		char selection{};
		std::cin >> selection;
		switch (selection) {
			case 'y':
				boxes.clear();
				std::cout << "Deleted all boxes.\n";
				return;

			case 'n':
				return;

			default:
				extractionErrorHandling();
		}
	}
}