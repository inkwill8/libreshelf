#include "../include/menu.h"

void Menu::DisplayMainMenu() {
	
	std::cout << "Menu Choices:" << std::endl;
	std::cout << "1. List All Books\n";
	std::cout << "2. List Books by Status\n";
	std::cout << "3. Search for Book\n";
	std::cout << "4. Add Book\n";
	std::cout << "5. Edit Metadata\n";
	std::cout << "6. Remove Book\n";
	std::cout << "0. Quit LibreShelf\n";
	
	// Initialize a variable for the menu choice and open an input
	// stream from the console
	
	std::cout << "Choice: ";
	int userChoice;
	std::cin >> userChoice;
	
	do {
	switch(userChoice) {
		case 1:
		  Menu::ShowAllBooks();
	} while (userChoice != 0);
};

void Menu::ShowAllBooks() {
	std::cout << "Show All books called!";
