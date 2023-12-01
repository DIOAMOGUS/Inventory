#pragma once
#include <iostream>
#include <string>
#include <string_view>

class Box {
public:
	// Box constructor
	Box(uint32_t boxID, std::string_view stuff);

	~Box();

	// Getters
	uint32_t getID() { return m_boxID; }
	const std::string& getStuff() { return m_stuff; }

	// Setters
	void setStuff(std::string_view stuff) { m_stuff = stuff; }

private:
	uint32_t m_boxID{};
	std::string m_stuff{};
};

// Box functions 
// Finds the desired box
uint32_t findBox(std::vector<Box>& boxes, const uint32_t desiredboxID);

// Creates a new Box
void createBox(std::vector<Box>& boxes, const uint32_t desiredBoxID);

// Prints a box's contents
void printBox(std::vector<Box>& boxes, const uint32_t indexOfBox);

// Edits a box's contents, not its ID
void editBox(std::vector<Box>& boxes, const uint32_t indexOfBox);

// Lists all the boxes in ascending order
void listBoxes(std::vector<Box>& boxes);

// Deletes the last created box
void deleteBox(std::vector<Box>& boxes, const uint32_t indexOfBox);

// Deletes all boxes, resetting the vector
void deleteAllBoxes(std::vector<Box>& boxes);