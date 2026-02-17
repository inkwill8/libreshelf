#pragma once
#include "book.h"
#include <fstream>
#include <sstream>
#include <vector>

class Library {

private:
  std::vector<Book> library;
  std::string filename = "data/books.csv";

  // CSV METHODS
  std::vector<Book> ReadFromCSV(const std::string &filename);
  void WriteToCSV(const std::string &filename);
  bool AppendToCSV(const std::string &filename, Book book);

public:
  void LoadLibrary(const std::string &filename);
  std::vector<Book *> SearchBooks(const std::string &bookName);
  bool AddBook(std::string &title, std::string &author, std::string &isbn,
               std::string &genre, std::string &status, std::string &rating);
  bool RemoveBook(const std::string &bookToDelete);
  Book EditMetadata(const std::string &bookName, const std::string &field, const std::string &newData);
  std::vector<Book> FilterByTrait(const std::string &trait);

  std::vector<Book> GetAllBooks() const;
  std::string GetFilename() const;
};
