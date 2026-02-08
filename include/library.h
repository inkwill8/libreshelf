#pragma once
#include "book.h"
#include <vector>
#include <fstream>
#include <sstream>

class Library {

private:
	std::vector<Book> library;

public:
	void LoadFromCSV(const std::string& filename);
	std::vector<Book*> SearchBooks(const std::string& bookName);
	bool AddBook(std::string& title, std::string& author, std::string& isbn, std::string& genre, std::string& status, std::string& rating);
	void EditMetadata();
	void RemoveBook();


	std::vector<Book> GetAllBooks() const;
};
