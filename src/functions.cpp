#include <fstream>
#include <iostream>
#include <unordered_map>
#include "box.hpp"
#include "functions.hpp"
#include "macros.hpp"

const std::string inputName()
{
	std::cout << "Input a Name:\n";
	std::string desiredBoxName{};
	std::getline(std::cin >> std::ws, desiredBoxName);
	
	return desiredBoxName;
}

char mainMenu(char userInput)
{
	std::cout << "\nc: create a box\np: print a box\ne: edit a box\nl: list all boxes\nd: delete a box\nx: delete all boxes\nw: wipe the screen\nq: quit\n";
	std::cin >> userInput;
	return userInput;
}

void wipeScreen() // no idea if there's a function i can call on each platform im just doing it like this ig
{
#ifdef _WIN32
	system("cls");
#elif __linux__
	system("clear");
#elif __APPLE__
	system("clear");
#endif
}

void exit()
{	
	// unordered_map is freed here
	std::cout << "\nThanks for playing!\n -DIO";
	std::exit(0);
}

void extractionErrorHandling()
{
	// let's handle the failure
	std::cin.clear(); // put us back in 'normal' operation mode
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // and remove the bad input
	std::cerr << "Error! That input was invalid. Please try again.\n";
}