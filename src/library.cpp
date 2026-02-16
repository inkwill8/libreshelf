#include "../include/library.h"
#include "../include/helper.h"
#include <fstream>
#include <sstream>
#include <string>

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
  bool isAppended = Library::AppendToCSV(filename, newBook);

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

  // Case validate bookToDelete
  std::string lowerBookToDelete = Helper::ToLowercase(bookToDelete);

  if (searchResults.empty()) {
    return false;
  } else {
    // Flag to track if the current book was removed or not
    bool wasRemoved;

    // If current book title and name parameter match, erase book from the
    // in-memory library vector
    for (int i = 0; i < library.size(); i++) {
      std::string currentBookTitle = library[i].GetTitle();
      std::string lowerBookTitle = Helper::ToLowercase(currentBookTitle);

      if (lowerBookTitle == lowerBookToDelete) {
        library.erase(library.begin() + i);
        wasRemoved = true;
        break;
      }
    }
    // Re-write the CSV with the newly edited library vector
    if (wasRemoved) {
      WriteToCSV(filename);
    };
    return wasRemoved;
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
           << currentBook.GetStrStatus() << ',' << currentBook.GetRating()
           << "\n";
    }

    file.close();
  }
};

Book Library::EditMetadata(const std::string &bookName,
                           const std::string &field,
                           const std::string &newData) {
  // Load the books into library if empty
  if (library.empty()) {
    LoadLibrary(filename);
  }

  // Search library for the desired book
  auto searchResults = SearchBooks(bookName);

  // If no search results, exit function
  //  if (searchResults.empty()) { return; }

  // Case validation
  std::string lowerField = Helper::ToLowercase(field);
  std::string lowerBookName = Helper::ToLowercase(bookName);

  // Call default book object as placeholder for return
  Book editedBook;

  for (int i = 0; i < searchResults.size(); i++) {
    Book currentBook = *searchResults[i];
    std::string currentBookTitle = Helper::ToLowercase(currentBook.GetTitle());

    if (currentBookTitle == lowerBookName) {
      // Edited book needs to equal current book
      editedBook = currentBook;

      // Set the desired field
      if (lowerField == "title") {
        editedBook.SetTitle(newData);
      }
      if (lowerField == "author") {
        editedBook.SetAuthor(newData);
      }
      if (lowerField == "isbn") {
        editedBook.SetIsbn(newData);
      }
      if (lowerField == "genre") {
        editedBook.SetGenre(
            Helper::StrToGenre(Helper::ToStandardFormat((newData))));
      }
      if (lowerField == "status") {
        editedBook.SetStatus(Helper::StrToStatus(newData));
      }
      if (lowerField == "rating") {
        editedBook.SetRating(std::stof(newData));
      }
      break;
    }
  }

  // Add the new book and remove the old entry from library
  library.push_back(editedBook);
  RemoveBook(bookName);

  return editedBook;
};
