// Inventory 1.2.3

/*
possible idea - make it like pokemon boxes, with multiple things in 1 box (array of strings (?))
other idea - write shit to a save file thing (fstream)
use 3rd party library "fmt" to print stuff
use a std::unordered_map (hash table) to look up the elements in the functions instead of looping over every variable looking for an id, this is MUCH faster
especially when you have tons and tons of boxes, algorithm will get beri beri slow!!
*/

#include <iostream>
#include <vector>
#include "box.hpp"
#include "functions.hpp"
#include "macros.hpp"

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
	gameStatus();
	return 0;
}
