#include "../include/library.h"
#include "../include/helper.h"
#include <fstream>
#include <sstream>

std::vector<Book> Library::GetAllBooks() const { return library; };
std::string Library::GetFilename() const { return filename; };

void Library::LoadLibrary(const std::string &filename) {
  std::vector<Book> books = ReadFromCSV(filename);

  for (auto &book : books) {
    library.push_back(book);
  }
};

std::vector<Book *> Library::SearchBooks(const std::string &searchTerm) {
  // If library is empty, parse CSV and populate it
  if (library.empty()) {
    LoadLibrary(filename);
  }

  // Create a temp vector to hold results
  std::vector<Book *> results;

  // Loop over library and look for search term
  for (int i = 0; i < library.size(); i++) {
    // Define the current book title and make it lowercase
    std::string currentBookTitle = library[i].GetTitle();
    std::string lowerBookTitle = Helper::ToLowercase(currentBookTitle);

    // Make search term lowercase for comparison
    std::string lowerSearchTerm = Helper::ToLowercase(searchTerm);

    // If current book title contains the search term, push it to the result
    // vector
    if (lowerBookTitle.contains(lowerSearchTerm)) {
      results.push_back(&library[i]);
    }
  }

  return results;
};

bool Library::AddBook(std::string &title, std::string &author,
                      std::string &isbn, std::string &genre,
                      std::string &status, std::string &rating) {
  // Returns true if successfully added, false if not

  // Title Validation
  std::string lowercaseTitle = Helper::ToLowercase(title);
  std::string formattedTitle = Helper::ToStandardFormat(lowercaseTitle);

  // Author Validation
  std::string lowercaseAuthor = Helper::ToLowercase(author);
  std::string formattedAuthor = Helper::ToStandardFormat(lowercaseAuthor);

  // Genre Validation
  std::string lowercaseGenre = Helper::ToLowercase(genre);
  std::string uppercaseGenre = Helper::ToStandardFormat(lowercaseGenre);
  Genre formattedGenre = Helper::StrToGenre(uppercaseGenre);

  // Status Validation
  Status formattedStatus = Helper::StrToStatus(status);

  // Rating Validation
  float formattedRating = std::stof(rating);

  // Build a book with validated user input
  Book newBook(formattedTitle, formattedAuthor, isbn, formattedGenre,
               formattedStatus, formattedRating);

  // Add the new book to the in-memory library vector
  library.push_back(newBook);

  // Append the new book to the CSV file
  bool isAppended = Library::AppendToCSV("../data/books.csv", newBook);

  return isAppended;
};

bool Library::AppendToCSV(const std::string &filename, Book book) {
  std::ofstream file(filename, std::ios::app);
  if (file.is_open()) {
    file << book.GetTitle() << "," << book.GetAuthor() << "," << book.GetIsbn()
         << "," << Helper::GenreToStr(book.GetGenre()) << ","
         << Helper::StatusToStr(book.GetStatus()) << "," << book.GetRating();
    file << "\n";
    file.close();
    return true;
  }

  return false;
};

bool Library::RemoveBook(const std::string &bookToDelete) {
  // Search for desired book in library vector first
  auto searchResults = SearchBooks(bookToDelete);
  if (searchResults.empty()) {
    return false;
  } else {
    // Erase the book from the in-memory library vector
    for (int i = 0; i < library.size(); i++) {
      Book currentBook = library[i];
      if (currentBook.GetTitle() == bookToDelete) {
        library.erase(library.begin() + i);
      }
    }
    // Re-write the CSV with the newly edited library vector
    WriteToCSV(filename);
  }
};

std::vector<Book> Library::ReadFromCSV(const std::string &filename) {
  // Declare a vector to hold loaded books
  std::vector<Book> loadedBooks;

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
    Genre genre =
        genreStr.empty() ? Genre::UNKNOWN : Helper::StrToGenre(genreStr);
    Status status =
        statusStr.empty() ? Status::UNKNOWN : Helper::StrToStatus(statusStr);
    float rating = ratingStr.empty() ? 0.0f : std::stof(ratingStr);

    // Instantiate a book object
    Book currentBook = Book(title, author, isbn, genre, status, rating);
    loadedBooks.push_back(currentBook);
  }
  books.close();

  return loadedBooks;
};

void Library::WriteToCSV(const std::string &filename) {
  std::ofstream file(filename);

  if (file.is_open()) {
    // Iterate over the libary vector to get our books
    for (int i = 0; i < library.size(); i++) {
      Book currentBook = library[i];
      file << currentBook.GetTitle() << ',' << currentBook.GetAuthor() << ','
           << currentBook.GetIsbn() << ',' << currentBook.GetStrGenre() << ','
           << currentBook.GetStrStatus() << ',' << currentBook.GetRating() << "\n";
      file.close();
    }
  }
};
