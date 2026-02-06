#include "../include/library.h"
#include "../include/helper.h"


void Library::LoadFromCSV(const std::string& filename) {
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


std::vector<Book*> Library::SearchBooks(const std::string& searchTerm) {
	// If library is empty, parse CSV and populate it
	if (library.empty()) {
	  LoadFromCSV("../data/books.csv");
	}
	
	// Create a temp vector to hold results
	std::vector<Book*> results;

	// Loop over library and look for search term
	for (int i = 0; i < library.size(); i++) {
		// Define the current book and make it lowercase
		std::string currentBookTitle = library[i].GetTitle();
		std::string lowerBookTitle = Helper::ToLowercase(currentBookTitle);

		// Make search term lowercase for comparison
		std::string lowerBookName = Helper::ToLowercase(searchTerm);

		// If current book title contains the search term, push it to the result vector
		if (lowerBookTitle.contains(lowerBookName)) {
		  results.push_back(&library[i]);
		}
	}

	return results;
};

void Library::AddBook(const std::string& title, const std::string& author, const std::string& isbn, Genre& genre, Status& status, float& rating) {
	
};

std::vector<Book> Library::GetAllBooks() const { return library; };
