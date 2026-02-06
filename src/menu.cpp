#include "../include/menu.h"
#include "../include/helper.h"
#include "../include/library.h"
#include <sstream>

void Menu::DisplayMainMenu() {
	
	int userChoice;
	library.LoadFromCSV("../data/books.csv"); // Parse the CSV file once before program starts

	do {
	DisplayMenuOptions();
	std::cin >> userChoice;

	switch(userChoice) {
		case 1:
		  ShowAllBooks(library);
		  std::cin >> userChoice;
		  break;

		case 2:
		  break;

		case 3:
		  std::cout << "\n\nEnter Book Title: ";
		  std::cin.ignore();
		  std::string searchTerm;
		  std::getline(std::cin, searchTerm);
		  std::vector<Book*> results = library.SearchBooks(searchTerm);
		  OutputSearchResults(results);
	}
	} while (userChoice != 0);
};


void Menu::ShowAllBooks(std::vector<Book>& books) {
	std::cout << "\n-----------------------------------------------\n";
	for (const auto& book : books) {
		std::cout << book << std::endl;
	}

	// Show total number of books
	std::cout << "\nBooks in Library: ";
	std::cout << library.size();
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

void Menu::OutputSearchResults(const std::vector<Book*>& results) {
	if (!results.empty()) {
	  std::cout << results.size() << " Results Found:" << std::endl;
	  for (const auto& result : results) {
		std::cout << *result << std::endl;
	  }
	} else {
		std::cout << "No Results Found!" << std::endl;
	}
	std::cout << "\n--------------------------------\n\n" << std::endl;
};












