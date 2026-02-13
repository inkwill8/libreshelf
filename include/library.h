#pragma once
#include "book.h"
#include <fstream>
#include <sstream>
#include <vector>

class Library {

private:
  std::vector<Book> library;
  std::string filename = "../data/books.csv";

  // CSV METHODS
  std::vector<Book> ReadFromCSV(const std::string &filename);
  Book RemoveFromCSV(const std::string &filename,
                     const std::string &bookToDelete);

public:
  void LoadLibrary(const std::string &filename);
  bool AppendToCSV(const std::string &filename, Book book);
  std::vector<Book *> SearchBooks(const std::string &bookName);
  bool AddBook(std::string &title, std::string &author, std::string &isbn,
               std::string &genre, std::string &status, std::string &rating);
  bool RemoveBook(const std::string &bookToDelete);
  void EditMetadata();

  std::vector<Book> GetAllBooks() const;
};
