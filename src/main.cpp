// Inventory 1.2

/*

deconstruct everything and deallocate vector at the end (i think i have to do that) HAHA NVM RAII BITCHESS

figure out how to edit the ids by moving the boxID into the index of the vector
(if ID is 64, move it into index 64)
check if a box is already in use

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
	char userInput{}; // Self-explanatory, controls the input and user commands in the main menu
	std::vector<Box> vboxes{}; // Vector to store the objects of the box class

	Box box{0, "nothing"}; // Creating our first box object
	vboxes.emplace(vboxes.begin(), box); // Dynamically pushing it to the vector
	system("cls");

	// Start of the program
	std::cout << "Hello! Please create your first box!\n";
	box.createBox(vboxes, 1);

	int desiredBoxID{};
	int indexOfBox{};

	// Moved this to a function as it was too crowded, poor main
	gameStatus(vboxes, box, userInput, indexOfBox, desiredBoxID);
	return 0;
}
