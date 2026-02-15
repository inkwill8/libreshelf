#include "../include/menu.h"
#include "../include/helper.h"
#include "../include/library.h"
#include <string>

void Menu::DisplayMainMenu() {

  int userChoice;

  // Parse the CSV file once before program starts
  library.LoadLibrary(library.GetFilename());

  do {
    DisplayMenuOptions();
    std::cin >> userChoice;

    switch (userChoice) {
    case 1:
      ShowAllBooks(library);
      break;

    case 2:
      break;

    case 3: {
      // Clear the input buffer after the user's menu choice
      std::cin.ignore();
      std::cout << "\n\nEnter Book Title: ";
      std::string searchTerm;
      std::getline(std::cin, searchTerm);
      std::vector<Book *> results = library.SearchBooks(searchTerm);
      OutputSearchResults(results);
      break;
    }

    case 4: {
      std::cin.ignore();

      // Initialize vars for book constructor
      std::string title, author, isbn, genre, status, rating;

      std::cout << "\n\n=== Add a Book ===\n";
      std::cout << "** Press Enter to Skip a Field **\n";
      std::cout << "Title: ";
      std::getline(std::cin, title);

      std::cout << "Author: ";
      std::getline(std::cin, author);

      std::cout << "ISBN: ";
      std::getline(std::cin, isbn);

      std::cout << "Genre: ";
      std::getline(std::cin, genre);

      std::cout << "Status: ";
      std::getline(std::cin, status);

      std::cout << "Rating (1 - 5): ";
      std::getline(std::cin, rating);

      bool isAppended =
          library.AddBook(title, author, isbn, genre, status, rating);
      isAppended == true ? std::cout << "Successfully added!\n\n"
                         : std::cout << "Something went wrong :(\n\n";

      break;
    }

    case 5: {
      std::cin.ignore();
      std::string bookName;
      std::string field;
      std::string newData;

      std::cout << "\n\n=== Edit a Book ===\n";
      std::cout << "Which book would you like to edit?\n";
      std::cout << "Enter Title: ";
      std::getline(std::cin, bookName);

      std::cout << "\n == " << Helper::ToStandardFormat(bookName) << " ==\n";
      std::cout << "What data would you like to change?\n";
      std::cout << "Options:"
                   "\n\tTitle\n\tAuthor\n\tIsbn\n\tGenre\n\tStatus\n\tRating\n";

      std::cout << "Data: ";
      std::getline(std::cin, field);
      std::cout << "Enter the new data: ";
      std::getline(std::cin, newData);

      Book editedBook = library.EditMetadata(bookName, field, newData);
      std::cout << "Edited Book: " << editedBook << "\n";
      break;
    }

    case 6: {
      std::cin.ignore();
      std::string bookTitle;

      std::cout << "\n\n=== Remove a Book ===\n";
      std::cout << "Enter Title: ";
      std::getline(std::cin, bookTitle);

      bool isRemoved = library.RemoveBook(bookTitle);
      if (isRemoved) {
        std::cout << bookTitle << " successfully removed!\n\n" << std::endl;
      } else {
        std::cout << bookTitle << " was not found.\n\n" << std::endl;
      }

      break;
    }
    }
  } while (userChoice != 0);
};

void Menu::ShowAllBooks(const Library &books) {
  std::cout << "\n-----------------------------------------------\n";
  for (const auto &book : books.GetAllBooks()) {
    std::cout << book << std::endl;
  }

  // Show total number of books
  std::cout << "\nBooks in Library: ";
  std::cout << books.GetAllBooks().size();
  std::cout << "\n\n";
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

void Menu::OutputSearchResults(const std::vector<Book *> &results) {
  if (!results.empty()) {
    std::cout << results.size() << " Results Found:" << std::endl;
    for (const auto &result : results) {
      std::cout << *result << std::endl;
    }
  } else {
    std::cout << "No Results Found!" << std::endl;
  }
  std::cout << "\n--------------------------------\n\n" << std::endl;
};
