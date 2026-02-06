#pragma once
#include <iostream>
#include <vector>
#include "book.h"
#include "library.h"

class Menu {
private:
	Library library;

public:
	void DisplayMainMenu();
	void DisplayMenuOptions();
	void ShowAllBooks(const Library& books);
	void OutputSearchResults(const std::vector<Book*>& results); 

};
