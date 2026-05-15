#pragma once
#include "book.h"
#include "library.h"
#include "openlibrary.h"
#include <iostream>
#include <vector>

class Menu {
private:
  Library library;
  OpenLibClient client;

public:
  void DisplayMainMenu();
  void DisplayMenuOptions();
  void ShowAllBooks(const Library &books);
  void OutputSearchResults(const std::vector<Book *> &results);
};
