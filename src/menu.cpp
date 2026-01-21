#include "../include/menu.h"
#include "../include/helper.h"

void Menu::DisplayMainMenu() {
	
	int userChoice;

	do {
	DisplayMenuOptions();
	std::cin >> userChoice;

	switch(userChoice) {
		case 1:
		  ParseCSV("books.csv");
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
		std::string title, author, isbn, genre, status, ratingStr;

		// Parse each field from the line
		std::getline(bookLine, title, ',');
		std::getline(bookLine, author, ',');
		std::getline(bookLine, isbn, ',');
		std::getline(bookLine, genreStr, ',');
		std::getline(bookLine, statusStr, ',');
		std::getline(bookLine, ratingStr, ',');

		// Convert from string to correct types
		Genre genre = Helper::strToGenre(genreStr);
		Status status = Helper::strToStatus(statusStr);
		float rating = std::stof(ratingStr);
		
		// Push each book object into library vector
		Book currentBook = Book(title, author, isbn, genre, status, rating);
		library.push_back(currentBook);
	}
	books.close();

	DisplayMenuOptions();
};

void Menu::ShowAllBooks(std::vector<Book>& books) {
	for (const auto book : books) {
		std::cout << book << std::endl;
	}
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
