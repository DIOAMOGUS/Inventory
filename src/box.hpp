#pragma once
#include <iostream>
#include <string>
#include <string_view>

class Box {
public:
	// Box constructor
	Box(uint32_t boxID, std::string_view stuff);

	// Classes don't "require" a destructor, as a default one will get created by the compiler, 
	// hence why i don't explicitly specify one here
	// ~Box();

	// Getters
	int getID() { return m_boxID; }
	const std::string& getStuff() { return m_stuff; }

	// Box member functions (also called methods)
	// Finds the desired box
	int findBox(const std::vector<Box>& boxes, const uint32_t desiredboxID) const;

	// Creates a new Box
	void createBox(std::vector<Box>& boxes, const uint32_t desiredBoxID);

	// Prints a box's contents
	void printBox(const std::vector<Box>& boxes, uint32_t indexOfBox) const;

	// Edits a box's contents, not its ID
	void editBox(std::vector<Box>& boxes, const uint32_t indexOfBox);

	// Lists all the boxes in ascending order
	void listBoxes(const std::vector<Box>& boxes) const;

	// Deletes the last created box
	void deleteBox(std::vector<Box>& boxes, const uint32_t indexOfBox);

private:
	uint32_t m_boxID{};
	std::string m_stuff{};
};
