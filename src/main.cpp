// inventory 1.1.1!!

/*
Things to do:
be able to print the value of a specified box
create a box					- done
edit the boxes					- done
delete boxes					- done
quit the program				- done
list all boxes					- done

deconstruct everything and deallocate vector at the end (i think i have to do that)
careful with string_view and shit though so you don't get undefined behaviour

bugs:
fix input error if whitespace 	- done

figure out how to edit the ids by moving the boxID into the index of the vector
(if ID is 64, move it into index 64)
check if a box is already in use

possible idea - make it like pokemon boxes, with multiple things in 1 box (array of strings (?))
other idea - write shit to a save file thing 

plan for custom box IDs
use inputID() function on all cases,
maybe rewrite the findbox() function so it looks for all the id's and saves the index of the boxes if it finds them (or vice-versa idk)
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
	int lastCreatedBoxID{}; // Variable to control the ids of the boxes, as you can't specify the id (yet)
	std::vector<Box> vboxes{}; // Vector to store the objects of the box class

	Box box{lastCreatedBoxID, "nothing"}; // Creating our first box object
	vboxes.emplace(vboxes.begin(), box); // Dynamically pushing it to the vector
	++lastCreatedBoxID;
	system("cls");

	// Start of the program
	std::cout << "Hello! Please create your first box!\n";
	box.createBox(vboxes, lastCreatedBoxID);

	while (true) {
		mainMenu(userInput);
		int desiredBoxID{};
		
		switch (userInput) {
		case 'c':
			box.createBox(vboxes, lastCreatedBoxID);
			break;

		case 'p':
			inputID(desiredBoxID);
			if (box.findBox(vboxes, desiredBoxID) == -1) // -1 meaning it failed
				continue; // start a new iteration of the loop if a box is not found

			box.printBox(vboxes, desiredBoxID);
			break;

		case 'e':
			inputID(desiredBoxID);
			if (box.findBox(vboxes, desiredBoxID) == -1) // -1 meaning it failed
				continue; // start a new iteration of the loop if a box is not found

			box.editBox(vboxes, desiredBoxID);
			break;

		case 'l':
			box.listBoxes(vboxes);
			break;

		case 'd':
			box.deleteLastBox(vboxes, lastCreatedBoxID);
			break;

		case 'q':
			cleanUp();
			break;

		case 'w':
			wipeScreen();
			break;

		default:
			std::cerr << "Error! Invalid input. Please try again.\n";
			break;
		}
	}
	return 0;
}
