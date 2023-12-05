#pragma once
#include <iostream>
#include <string>
#include <string_view>
#include "macros.hpp"

class Box {
public:
	// Box constructor
	Box(uint64_t boxID, std::string_view stuff);

	#ifdef DEBUG
	// Box copy constructor
	Box(const Box& box);
	#endif
	~Box();

	// Getters
	inline uint64_t getID() const { return m_boxID; } const
	inline const std::string& getStuff() const { return m_stuff; } const

	// Setters
	inline void setStuff(std::string_view stuff) { m_stuff = stuff; }

private:
	uint64_t m_boxID{};
	std::string m_stuff{};
};

// Box functions 
// Finds the desired box
uint64_t findBox(std::vector<Box>& boxes, const uint64_t desiredboxID);

// Creates a new Box
void createBox(std::vector<Box>& boxes, const uint64_t desiredBoxID);

// Prints a box's contents
void printBox(std::vector<Box>& boxes, const uint64_t indexOfBox);

// Edits a box's contents, not its ID
void editBox(std::vector<Box>& boxes, const uint64_t indexOfBox);

// Lists all the boxes in ascending order
void listBoxes(std::vector<Box>& boxes);

// Deletes the last created box
void deleteBox(std::vector<Box>& boxes, const uint64_t indexOfBox);

// Deletes all boxes, resetting the vector
void deleteAllBoxes(std::vector<Box>& boxes);