// Inventory 1.2.2

/*
possible idea - make it like pokemon boxes, with multiple things in 1 box (array of strings (?))
other idea - write shit to a save file thing (fstream)
use 3rd party library "fmt" to print stuff
use a std::unordered_map (hash table) to look up the elements in the functions instead of looping over every variable looking for an id, this is MUCH faster
especially when you have tons and tons of boxes, algorithm will get beri beri slow!!
*/
#include <iostream>
#include <memory>
#include <vector>
#include "box.hpp"
#include "functions.hpp"

#define DEBUG

#ifdef DEBUG
// Simple operator overloading to show heap allocations and deallocations
void* operator new(size_t size)
{
	std::cout << "Allocating " << size << " bytes\n";
	return malloc(size);
}

void operator delete(void* ptr, size_t size)
{
	std::cout << "Freeing " << size << " bytes\n";
	free(ptr);
}
#endif

int main()
{
	std::vector<Box> boxes{}; // Vector to store the objects of the box class 
	Box box{ 0, "nothing" }; // Creating our first box object
	boxes.emplace(boxes.begin(), box); // Dynamically pushing it to the vector
	system("cls");

	// Start of the program
	std::cout << "Hello! Please create your first box!\n";
	box.createBox(boxes, 1);

	// Moved this to a function as it was too crowded, poor main
	gameStatus(boxes, box);
	return 0;
}
