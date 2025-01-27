#pragma once
#include <iostream>
#include <string>
#include <string_view>
#include <unordered_map>
#include "macros.hpp"

class Box {
public:
	// Box constructor
	Box(std::string_view boxName = "defaultName", std::string_view boxData = "defaultData");
	// figure out why this shit needs default arguments?!?!!?

	#ifdef DEBUG
	// Box copy constructor
	Box(const Box& box);
	#endif
	~Box();

	// Getters
	inline std::string_view getName() const { return m_boxName; } const
	inline std::string_view getData() const { return m_boxData; } const

	// Setters
	inline const void setName(std::string_view name) { m_boxName = name; }
	inline const void setData(std::string_view data) { m_boxData = data; }

private:
	std::string m_boxName{};
	std::string m_boxData{};
};

// Box functions 
// Creates a new Box
void createBox(std::unordered_map<std::string, Box>& boxes, const std::string& boxName);

// Prints a box's contents
void printBox(std::unordered_map<std::string, Box>& boxes, const std::string& boxName);

// Edits a box's contents, not its ID
void editBox(std::unordered_map<std::string, Box>& boxes, const std::string& boxName);

// Lists all the boxes in ascending order
void listBoxes(std::unordered_map<std::string, Box>& boxes);

// Deletes the last created box
void deleteBox(std::unordered_map<std::string, Box>& boxes, const std::string& boxName);

// Deletes all boxes
void deleteAllBoxes(std::unordered_map<std::string, Box>& boxes);