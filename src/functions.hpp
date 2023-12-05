#pragma once
#include "box.hpp"

// Game loop
void gameStatus();

// User inputs the ID of the box they want to access/create
uint64_t inputID();

// Prints the main menu
void mainMenu(char& userInput);

// Wipes the screen using "cls"
inline void wipeScreen();

// Cleans up allocated memory and exits the program safely
void exit();

// Cleans up the input stream in case of an error
inline void extractionErrorHandling();