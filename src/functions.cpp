#include <iostream>
#include <limits>
#include "functions.hpp"

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void inputID(int& desiredBoxID)
{
	while (true) {
		std::cout << "Input an ID: (1 - 100)\n";
		std::cin >> desiredBoxID;

		if (desiredBoxID > 100 || desiredBoxID < 1 || !std::cin) {
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
