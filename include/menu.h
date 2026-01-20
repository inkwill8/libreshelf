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
	void ShowAllBooks(const std::string& filename);
	void SearchBooks();
	void EditMetadata();
	void RemoveBook();
	void QuitMenu();

};
