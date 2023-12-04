#include <iostream>
#include <limits>
#include <vector>

#include "box.hpp"
#include "functions.hpp"
#include "macros.hpp"

void gameStatus() {
	char userInput{};  // Self-explanatory, controls the input and user commands in the main menu
	uint32_t desiredBoxID{}; // Variable that holds the user's desired box 
	uint32_t indexOfBox{}; // Variable holding the index of the box in the vector, as the index and the ID are separate

	std::vector<Box> boxes{}; // Vector to store the boxes
	while (true) {
		mainMenu(userInput);
		switch (userInput) {
		case 'c':
			desiredBoxID = inputID();
			indexOfBox = findBox(boxes, desiredBoxID);

			// handle errors if box of the same id is already found
			if (indexOfBox == -1) // -1 meaning it didn't find a box
				createBox(boxes, desiredBoxID);
			else
				std::cout << "That box is in use already.\n";
			break;

		case 'p':
			desiredBoxID = inputID();
			indexOfBox = findBox(boxes, desiredBoxID);

			if (indexOfBox == -1) { // -1 meaning it didn't find a box
				std::cerr << "Error! No box found!\n";
				continue; // start a new iteration of the loop if a box is not found
			}
			printBox(boxes, indexOfBox);
			break;

		case 'e':
			desiredBoxID = inputID();
			indexOfBox = findBox(boxes, desiredBoxID);

			if (indexOfBox == -1) { // -1 meaning it didn't find a box 
				std::cerr << "Error! No box found!\n";
				continue; // start a new iteration of the loop if a box is not found
			}
			editBox(boxes, indexOfBox);
			break;

		case 'l':
			listBoxes(boxes);
			break;

		case 'd':
			desiredBoxID = inputID();
			indexOfBox = findBox(boxes, desiredBoxID);

			if (indexOfBox == -1) { // -1 meaning it failed
				std::cerr << "Error! No box found!\n";
				continue; // start a new iteration of the loop if a box is not found
			}
			deleteBox(boxes, indexOfBox);
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

uint64_t inputID()
{
	uint64_t desiredBoxID{};
	while (true) {
		std::cout << "Input an ID: (Minimum = 0)\n";
		std::cin >> desiredBoxID;

		if (!std::cin || desiredBoxID < 0) {
			extractionErrorHandling();
		}
		else
			break;
	}
	return desiredBoxID;
}

void mainMenu(char& userInput)
{
	std::cout << "\nc: create a box\np: print a box\ne: edit a box\nl: list all boxes\nd: delete a box\nx: delete all boxes\nw: wipe the screen\nq: quit\n";
	std::cin >> userInput;
}

void wipeScreen()
{
	system("cls"); // Don't do this though because this shit isn't very portable lmfao
}

void exit()
{
	std::cout << "Thanks for playing!\n -DIO";
	std::exit(0);
}

void extractionErrorHandling()
{
	// let's handle the failure
	std::cin.clear(); // put us back in 'normal' operation mode
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // and remove the bad input
	std::cerr << "Error! That input was invalid. Please try again.\n";
}