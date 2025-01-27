// Inventory 1.4

/*
possible idea - make it like pokemon boxes, with multiple things in 1 box (array of strings (?))
other idea - write shit to a save file thing (fstream)
use 3rd party library "fmt" to print stuff
*/

#include <iostream>
#include "box.hpp"
#include "functions.hpp"
#include "macros.hpp"

#ifdef DEBUG
// Simple operator overloading to show heap allocations and deallocations
void* operator new(size_t size)
{
	std::cout << "Allocating " << size << " bytes\n";
	return malloc(size);
}

void operator delete(void* ptr, size_t size)
{
	std::cout << "Freeing " << size << " bytes\n";
	free(ptr);
}
#endif

int main()
{
	char userInput{}; // Self-explanatory, controls the input and user commands in the main menu
	std::string boxName{}; // Variable that holds the name of the user's desired box
	std::string boxData{}; // Variable that holds the data of the user's desired box
	std::unordered_map<std::string, Box> boxes{}; // unordered_map (hash table) to store the boxes

	while (true) {
		userInput = mainMenu(userInput);
		switch (userInput) {
		case 'c':
			boxName = inputName();

			if (boxes.find(boxName) != boxes.end()) // if it found a box
				std::cerr << "That box is in use already.\n";
			else
				createBox(boxes, boxName);
			break;

		case 'p':
			boxName = inputName();

			if (boxes.find(boxName) != boxes.end()) // if it found a box
				printBox(boxes, boxName);
			else {
				std::cerr << "Error! No box found!\n";
				continue; // start a new iteration of the loop if a box is not found
			}
			break;

		case 'e':
			boxName = inputName();

			if (boxes.find(boxName) != boxes.end()) {
				editBox(boxes, boxName); // if it found a box
			} else {
				std::cerr << "Error! No box found!\n";
				continue; // start a new iteration of the loop if a box is not found
			}
			break;

		case 'l':
			listBoxes(boxes);
			break;

		case 'd':
			boxName = inputName();

			if (boxes.find(boxName) != boxes.end()) // if it found a box
				deleteBox(boxes, boxName);
			else {
				std::cerr << "Error! No box found!\n";
				continue; // start a new iteration of the loop if a box is not found
			}
			break;

		case 'x':
			deleteAllBoxes(boxes);
			break;

		case 'w':
			wipeScreen();
			break;

		case 'q':
			exit();
			break;

		default:
			extractionErrorHandling();
			break;
		}
	}
}