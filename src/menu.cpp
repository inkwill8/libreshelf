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

    case 2: {
      int numericChoice;
      std::string trait;
      bool isValid;

      std::cout << "\n\n=== Filter by Trait ===\n";
      std::cout << "Which trait would you like to filter by?\n";
      std::cout << "Options:";
      std::cout << "\n\t1. Author\n\t2. Genre\n\t3. Status\n\t4. Rating";
      std::cout << "\nEnter numeric choice: ";
      std::cin >> numericChoice;
      std::cin.ignore();

      // Determine which to run based on chosen case
      switch (numericChoice) {
      case 1: {
        std::string author;

        std::cout << "\n\nAuthor Name: ";
        std::getline(std::cin, author);

        std::cout << "\n\n== Books by " << Helper::ToStandardFormat(author)
                  << " ==\n";
        author.push_back('$'); // Add an identifier to the end of the string so
                               // FilterByStatus knows what type of trait it is
        trait = Helper::ToLowercase(author);
        isValid = true;
        break;
      }

      case 2: {
        std::string genre;
        int choice;

        std::cout << "\n\nWhich genre?\n";
        std::cout << "Options: \n";
        std::cout
            << "\t1.Biography\n\t2.Memoir\n\t3.Fantasy\n\t4.Sci-fi\n\t5.Young "
               "Adult\n\t6.Historical "
               "Fiction\n\t7.Romance\n\t8.Horror\n\t9.Thriller\n\t10.Unknown";

        std::cout << "\nChoice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
          genre = "Biography";
          break;

        case 2:
          genre = "Memoir";
          break;

        case 3:
          genre = "Fantasy";
          break;

        case 4:
          genre = "Sci-fi";
          break;

        case 5:
          genre = "Young Adult";
          break;

        case 6:
          genre = "Historical Fiction";
          break;

        case 7:
          genre = "Romance";
          break;

        case 8:
          genre = "Horror";
          break;

        case 9:
          genre = "Thriller";
          break;

        case 10:
          genre = "Unknown";
          break;

        default:
          std::cout << "Invalid genre.\n";
          break;
        }
        std::cout << "\n\n== " << genre << " Books ==\n";

        genre.push_back('%');
        trait = Helper::ToLowercase(genre);
        isValid = true;
        break;
      }

      case 3: {
        std::string status;

        std::cout << "\n\nEnter Status: ";
        std::cout << "\nOptions: ";
        std::cout << "\n\tWant to Read\n\tCurrently Reading\n\tFinished\n\tDid "
                     "Not Finish\n\tUnknown";

        std::cout << "\nChoice: ";
        std::getline(std::cin, status);

        std::cout << "\n\n== " << Helper::ToStandardFormat(status) << " ==\n";
        status.push_back('^');
        trait = Helper::ToLowercase(status);
        isValid = true;
        break;
      }

      case 4: {
        std::string rating;

        std::cout << "\n\nEnter Rating: ";
        std::cout << "\nOptions: ";
        std::cout << "\n\t1.0\n\t1.5\n\t2.0\n\t2.5\n\t3.0\n\t3.5\n\t4.0\n\t4."
                     "5\n\t5.0";

        std::cout << "\nChoice: ";
        std::getline(std::cin, rating);

        std::cout << "\n\n== " << rating << " Rated Books ==\n";
        rating.push_back('&');
        trait = rating;
        isValid = true;
        break;
      }
      default:
        std::cout << "Invalid choice.\n\n";
        isValid = false;
        break;
      }

      // Call FilterByTrait passing user given trait
      if (isValid) {
        std::vector<Book> filteredResults = library.FilterByTrait(trait);
        for (auto &result : filteredResults) {
          std::cout << result << "\n";
        }

        std::cout << filteredResults.size() << " results found.\n\n";
      }
      break;
    }
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
  std::cout << "2. Filter by Trait\n";
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
