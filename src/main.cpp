// Inventory 1.2

/*
possible idea - make it like pokemon boxes, with multiple things in 1 box (array of strings (?))
other idea - write shit to a save file thing 
use 3rd party library "fmt" to print stuff
*/

#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include "box.hpp"
#include "functions.hpp"

int main()
{
	std::vector<Box> vboxes{}; // Vector to store the objects of the box class

	Box box{0, "nothing"}; // Creating our first box object
	vboxes.emplace(vboxes.begin(), box); // Dynamically pushing it to the vector
	system("cls");

	// Start of the program
	std::cout << "Hello! Please create your first box!\n";
	box.createBox(vboxes, 1);

	// Moved this to a function as it was too crowded, poor main
	gameStatus(vboxes, box);
	return 0;
}
