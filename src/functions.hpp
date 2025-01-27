#pragma once
#include <string_view>
#include "box.hpp"

// User inputs the name of the box they want to access/create
const std::string inputName();

// Prints the main menu
char mainMenu(char userInput);

// Wipes the screen using "cls"
void wipeScreen();

// Cleans up allocated memory and exits the program safely
void exit();

// Cleans up the input stream in case of an error
void extractionErrorHandling();