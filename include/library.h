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
	void AddBook(const std::string& title, const std::string& author, const std::string& isbn, Genre& genre, Status& status, float& rating);
	void EditMetadata();
	void RemoveBook();


	std::vector<Book> GetAllBooks() const;
};
