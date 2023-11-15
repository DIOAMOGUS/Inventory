#pragma once
#include <iostream>
#include <string>
#include <string_view>

class Box {
public:
	// Box constructor
	Box(short boxID, std::string_view stuff);

	// Classes don't "require" a destructor, as a default one will get created by the compiler, 
	// hence why i don't explicitly specify one here
	// ~Box();

	// Getters
	int getID() { return m_boxID; }
	const std::string& getStuff() { return m_stuff; }

	// Box member functions (also called methods)
	// Finds the desired box
	int findBox(const std::vector<Box>& vboxes, short desiredboxID) const;

	// Creates a new Box
	void createBox(std::vector<Box>& vboxes, short desiredBoxID);

	// Prints a box's contents
	void printBox(const std::vector<Box>& vboxes, short indexOfBox) const;

	// Edits a box's contents, not its ID
	void editBox(std::vector<Box>& vboxes, short indexOfBox);

	// Lists all the boxes in ascending order
	void listBoxes(const std::vector<Box>& vboxes) const;

	// Deletes the last created box
	void deleteBox(std::vector<Box>& vboxes, short indexOfBox);

private:
	short m_boxID{};
	std::string m_stuff{};
};
