#include <iostream>
#include <limits>
#include <vector>
#include "functions.hpp"
#include "box.hpp"

void gameStatus(std::vector<Box>& vboxes, Box box, char& userInput, int& indexOfBox, int& desiredBoxID){
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
}

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int inputID()
{
	int desiredBoxID{};
	while (true) {
		std::cout << "Input an ID: (Minimum = 1)\n";
		std::cin >> desiredBoxID;

		if (desiredBoxID < 1 || !std::cin) {
			if (std::cin.eof()) // if the stream was closed
			{
				std::exit(1); // shut down the program now
			}
			// let's handle the failure
			std::cin.clear(); // put us back in 'normal' operation mode
			ignoreLine(); // and remove the bad input
			std::cerr << "Error! That input was either invalid, or you exceeded the ID limit. Please try again.\n";
		} else
			break;
	}
	return desiredBoxID;
}

void mainMenu(char& userInput)
{
	std::cout << "\nc: create a box\np: print a box\ne: edit a box\nl: list all boxes\nd: delete last box\nw: wipe the screen\nq: quit\n";
	std::cin >> userInput;
}

void wipeScreen()
{
	system("cls"); // Don't do this though because this shit isn't very portable lmfao
}

void cleanUp()
{
	// clean up code here because i think im gonna use arrays or vectors and shit so yeah

	std::cout << "Thanks for playing!\n -DIO";
	std::exit(0);
}
