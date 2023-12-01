#pragma once
#include "box.hpp"

// Game loop
void gameStatus();

// User inputs the ID of the box they want to access/create
uint32_t inputID();

// Prints the main menu
void mainMenu(char& userInput);

// Wipes the screen using "cls"
void wipeScreen();

// Cleans up allocated memory and exits the program safely
void exit();

// Cleans up the input stream in case of an error
void extractionErrorHandling();