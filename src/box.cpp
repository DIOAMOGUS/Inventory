#include <iostream>
#include <memory>
#include <string>
#include <string_view>
#include <unordered_map>
#include "box.hpp"
#include "functions.hpp"
#include "macros.hpp"

Box::Box(std::string_view boxName, std::string_view boxData)
	: m_boxName{ boxName }
	, m_boxData{ boxData }
{
	std::cout << "Successfully constructed the box.\n";
#ifdef DEBUG
	std::cout << "Box Name: " << m_boxName << '\n' << "Box Data: " << m_boxData << '\n';
#endif
}

#ifdef DEBUG
Box::Box(const Box& box)
	: m_boxName{ box.m_boxName }
	, m_boxData{ box.m_boxData }
{
	std::cout << "Copy constructor called\n";
	std::cout << "Box Name: " << m_boxName << '\n' << "Box Data: " << m_boxData << '\n';
}
#endif

Box::~Box() {}

void createBox(std::unordered_map<std::string, Box>& boxes, const std::string& boxName)
{
	std::cout << "What will you store in your box?\n";
	std::string boxData{};
	std::getline(std::cin >> std::ws, boxData);

	// Creating the box
	boxes.emplace(boxName, Box{boxName, boxData});
}

void printBox(std::unordered_map<std::string, Box>& boxes, const std::string& boxName)
{
	std::cout << "This box contains:\n" << boxes.at(boxName).Box::getData() << '\n';
}

void editBox(std::unordered_map<std::string, Box>& boxes, const std::string& boxName)
{
	std::cout << "What will you store in your box?\n";
	std::string boxData{};
	std::getline(std::cin >> std::ws, boxData);
	boxes.at(boxName).Box::setData(boxData);
	std::cout << "Successfully edited the box.\n";
}

void listBoxes(std::unordered_map<std::string, Box>& boxes)
{
	for (auto& [name, box] : boxes) {
		std::cout << "Box " << name << ":\nThis box contains:\n" << box.getData() << '\n';
	}
#ifdef DEBUG
	std::cout << "size of map = " << boxes.size() << '\n';
#endif
}

void deleteBox(std::unordered_map<std::string, Box>& boxes, const std::string& boxName)
{
	boxes.erase(boxName);
	std::cout << "Successfully destroyed the box.\n";
}

void deleteAllBoxes(std::unordered_map<std::string, Box>& boxes)
{
	while (true) {
		std::cout << "Are you sure you want to clear everything? y/n\n";
		char selection{};
		std::cin >> selection;
		switch (selection) {
			case 'y':
				boxes.clear();
				std::cout << "Deleted all boxes.\n";
				[[fallthrough]];

			case 'n':
				return;

			default:
				extractionErrorHandling();
		}
	}
}