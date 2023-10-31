#pragma once

// Ignores a line if std::cin extraction failed
void ignoreLine();

// User inputs the ID of the box they want to access/create
void inputID(int& desiredBoxID);

// Prints the main menu
void mainMenu(char& userInput);

// Wipes the screen using "cls"
void wipeScreen();

// Cleans up allocated memory and exits the program safely
void cleanUp();
