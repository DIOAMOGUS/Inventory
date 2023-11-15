#include <iostream>
#include <limits>
#include <vector>
#include "functions.hpp"
#include "box.hpp"

void gameStatus(std::vector<Box>& vboxes, Box& box){
	char userInput{};  // Self-explanatory, controls the input and user commands in the main menu
	short desiredBoxID{}; // Variable that holds the user's desired box 
	short indexOfBox{}; // Variable holding the index of the box in the vector, as the index and the ID are separate

	while (true) {
		mainMenu(userInput);
		switch (userInput){
		case 'c':
			desiredBoxID = inputID();
			indexOfBox = box.findBox(vboxes, desiredBoxID);

			// handle errors if box of the same id is already found
			if (indexOfBox == -1) // -1 meaning it didn't find a box 
				box.createBox(vboxes, desiredBoxID);
			else
				std::cout << "That box is in use already.\n";
			break;

		case 'p':
			desiredBoxID = inputID();
			indexOfBox = box.findBox(vboxes, desiredBoxID);
			
			if (indexOfBox == -1){ // -1 meaning it didn't find a box
				std::cerr << "Error! No box found!\n"; 
				continue; // start a new iteration of the loop if a box is not found
			}  
			box.printBox(vboxes, indexOfBox);
			break;

		case 'e':
			desiredBoxID = inputID();
			indexOfBox = box.findBox(vboxes, desiredBoxID);

			if (indexOfBox == -1){ // -1 meaning it didn't find a box 
				std::cerr << "Error! No box found!\n"; 
				continue; // start a new iteration of the loop if a box is not found
			}
			box.editBox(vboxes, indexOfBox);
			break;

		case 'l':
			box.listBoxes(vboxes);
			break;

		case 'd':
			desiredBoxID = inputID();
			indexOfBox = box.findBox(vboxes, desiredBoxID);

			if (indexOfBox == -1){ // -1 meaning it failed
				std::cerr << "Error! No box found!\n";
				continue; // start a new iteration of the loop if a box is not found
			} 
			box.deleteBox(vboxes, indexOfBox);
			break;

		case 'q':
			exit();
			break;

		case 'w':
			wipeScreen();
			break;

		default:
			std::cerr << "Error! Invalid input. Please try again.\n";
			break;
		}
	}
}

int inputID()
{
	short desiredBoxID{};
	while (true) {
		std::cout << "Input an ID: (Minimum = 1)\n";
		std::cin >> desiredBoxID;

		if (desiredBoxID < 1 || !std::cin) {
			// let's handle the failure
			std::cin.clear(); // put us back in 'normal' operation mode
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // and remove the bad input
			std::cerr << "Error! That input was invalid. Please try again.\n";
		} else
			break;
	}
	return desiredBoxID;
}

void mainMenu(char& userInput)
{
	std::cout << "\nc: create a box\np: print a box\ne: edit a box\nl: list all boxes\nd: delete box\nw: wipe the screen\nq: quit\n";
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
