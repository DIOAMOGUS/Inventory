#include <fstream>
#include <iostream>
#include <unordered_map>
#include "box.hpp"
#include "functions.hpp"
#include "macros.hpp"

void gameStatus() {
	char userInput{};  // Self-explanatory, controls the input and user commands in the main menu
	std::string boxName{}; // Variable that holds the user's desired box 
	std::unordered_map<std::string, Box> boxes{};// unordered_map (hash table) to store the boxes
	
	while (true) {
		mainMenu(userInput);
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

			if (boxes.find(boxName) != boxes.end()) { // if it found a box
				printBox(boxes, boxName);
			} 
			else {
				std::cerr << "Error! No box found!\n";
				continue; // start a new iteration of the loop if a box is not found
			}
			break;

		case 'e':
			boxName = inputName();

			if (boxes.find(boxName) != boxes.end()) {
				editBox(boxes, boxName); // if it found a box
			} 
			else {
				std::cerr << "Error! No box found!\n";
				continue; // start a new iteration of the loop if a box is not found
			}
			break;

		case 'l':
			listBoxes(boxes);
			break;

		case 'd':
			boxName = inputName();

			if (boxes.find(boxName) != boxes.end()) { // if it found a box
				deleteBox(boxes, boxName);
			} 
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

const std::string& inputName()
{
	std::string desiredBoxName{};
	std::cout << "Input a name:\n";
	std::getline(std::cin >> std::ws, desiredBoxName);
	
	return desiredBoxName;
}

void mainMenu(char& userInput)
{
	std::cout << "\nc: create a box\np: print a box\ne: edit a box\nl: list all boxes\nd: delete a box\nx: delete all boxes\nw: wipe the screen\nq: quit\n";
	std::cin >> userInput;
}

inline void wipeScreen()
{
	system("cls"); // Don't do this though because this shit isn't very portable lmfao
}

void exit()
{
	std::cout << "Thanks for playing!\n -DIO";
	std::exit(0);
}

inline void extractionErrorHandling()
{
	// let's handle the failure
	std::cin.clear(); // put us back in 'normal' operation mode
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // and remove the bad input
	std::cerr << "Error! That input was invalid. Please try again.\n";
}