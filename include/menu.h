#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "book.h"
#include "library.h"

class Menu {
private:
	Library library;

public:
	void DisplayMainMenu();
	void DisplayMenuOptions();
	void ShowAllBooks(std::vector<Book>& books);
	void OutputSearchResults(const std::vector<Book*>& results); 

};
