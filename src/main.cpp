#include "../include/book.h"
#include "../include/types.h"
#include "../include/menu.h
#include <iostream>


int main() {
	std::cout << "##################" << std::endl;
	std::cout << "### LibreShelf ###" << std::endl;
	std::cout << "##################" << std::endl;

	std::cout << "Menu Choices:" << std::endl;
	std::cout << "1. List All Books\n";
	std::cout << "2. List Books by Status\n";
	std::cout << "3. Search for Book\n";
	std::cout << "4. Add Book\n";
	std::cout << "5. Edit Metadata\n";
	std::cout << "6. Remove Book\n";
	std::cout << "0. Quit LibreShelf\n";
	
	// Initialize a varible for the menu choice and open an input
	// stream from the console
	int userChoice;
	std::cin >> userChoice;


	return 0;
};
