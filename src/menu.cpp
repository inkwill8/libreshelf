#include "../include/menu.h"
#include "../include/helper.h"
#include <sstream>

void Menu::DisplayMainMenu() {
	
	int userChoice;

	do {
	DisplayMenuOptions();
	std::cin >> userChoice;

	switch(userChoice) {
		case 1:
		  ParseCSV("../data/books.csv");
		  ShowAllBooks(library);
		  std::cin >> userChoice;
		  break;
	}
	} while (userChoice != 0);
};

void Menu::ParseCSV(const std::string& filename) {
	std::ifstream books(filename);
	std::string line;	
	
	// SKIP HEADER LINE
	std::getline(books, line);

	// While the input stream is in a good state, read data
	while (std::getline(books, line)) {
		std::stringstream bookLine(line); // Open a stringstream for each line

		// Create member vars to hold each value temporarily
		std::string title, author, isbn, genreStr, statusStr, ratingStr;

		// Parse each field from the line
		std::getline(bookLine, title, ',');
		std::getline(bookLine, author, ',');
		std::getline(bookLine, isbn, ',');
		std::getline(bookLine, genreStr, ',');
		std::getline(bookLine, statusStr, ',');
		std::getline(bookLine, ratingStr, ',');

		// Convert from string to correct types with validation for empty fields
		Genre genre = genreStr.empty() ? Genre::UNKNOWN : Helper::StrToGenre(genreStr);
		Status status = statusStr.empty() ? Status::UNKNOWN : Helper::StrToStatus(statusStr);
		float rating = ratingStr.empty() ? 0.0f : std::stof(ratingStr);
		
		// Push each book object into library vector
		Book currentBook = Book(title, author, isbn, genre, status, rating);
		library.push_back(currentBook);
	}
	books.close();

	//DisplayMenuOptions();
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

std::vector<Book> Menu::GetLibrary() const { return library; };


std::vector<Book*> SearchBooks(const std::string& bookName) {
	// If library is empty, parse CSV and populate it
	if (library.empty()) {
	  ParseCSV("../data/books.csv");
	}
	
	// Create a temp vector to hold results
	std::vector<Book*> results;

	// Loop over library and look for search term
	for (int i = 0; i < library.size(); i++) {
		if (library[i]._title.contains(bookName)) {
		  results.push_back(&library[i]);
		}
	}

	return results;
};












