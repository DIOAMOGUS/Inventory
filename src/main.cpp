// Inventory 1.2

/*
possible idea - make it like pokemon boxes, with multiple things in 1 box (array of strings (?))
other idea - write shit to a save file thing (fstream)
use 3rd party library "fmt" to print stuff
use a std::unordered_map (hash table) to look up the elements in the functions instead of looping over every variable looking for an id, this is MUCH faster
especially when you have tons and tons of boxes, algorithm will get beri beri slow!!
*/
#include <iostream>
#include <vector>
#include "box.hpp"
#include "functions.hpp"

#include <core.h>

int main()
{
	std::vector<Box> boxes{}; // Vector to store the objects of the box class 
	Box box{0, "nothing"}; // Creating our first box object
	boxes.emplace(boxes.begin(), box); // Dynamically pushing it to the vector
	system("cls");

	// Start of the program
	fmt::print("Hello! Please create your first box!\n");
	box.createBox(boxes, 1);

	// Moved this to a function as it was too crowded, poor main
	gameStatus(boxes, box);
	return 0;
}
