#pragma once
#include <string_view>
#include "box.hpp"

// Game loop
void gameStatus();

// User inputs the name of the box they want to access/create
const std::string& inputName();

// Prints the main menu
void mainMenu(char& userInput);

// Wipes the screen using "cls"
inline void wipeScreen();

// Cleans up allocated memory and exits the program safely
void exit();

// Cleans up the input stream in case of an error
inline void extractionErrorHandling();