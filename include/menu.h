#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "book.h"

class Menu {
private:
	std::vector<Book> library;

public:
	void DisplayMainMenu();
	void DisplayMenuOptions();
	void ShowAllBooks(std::vector<Book>& books);
	void ParseCSV(const std::string& filename);
	std::vector<Book*> SearchBooks(const std::string& bookName);
	void OutputSearchResults(const std::vector<Book*>& results); 
	void EditMetadata();
	void RemoveBook();

	std::vector<Book> GetLibrary() const;
};
