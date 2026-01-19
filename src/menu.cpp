#include "../include/menu.h"

void Menu::DisplayMainMenu() {
	
	int userChoice;

	do {
	DisplayMenuOptions();
	
	std::cin >> userChoice;
	switch(userChoice) {
		case 1:
		  Menu::ShowAllBooks();
		  std::cin >> userChoice;
		  break;
	}
	} while (userChoice != 0);
};

void Menu::ShowAllBooks() {
	std::cout << "ShowAllBooks called!";
};

void Menu::DisplayMenuOptions() {
	std::cout << "Menu Choices:" << std::endl;
	std::cout << "1. List All Books\n";
	std::cout << "2. List Books by Status\n";
	std::cout << "3. Search for Book\n";
	std::cout << "4. Add Book\n";
	std::cout << "5. Edit Metadata\n";
	std::cout << "6. Remove Book\n";
	std::cout << "0. Quit LibreShelf\n";
	std::cout << "Choice: ";
};
