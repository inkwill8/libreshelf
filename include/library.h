#pragma once
#include "book.h"

class Library {

private:
	std::vector<Book> library;

public:
	void LoadFromCSV(const std::string& filename);
	std::vector<Book*> SearchBooks(const std::string& bookName);
	void EditMetadata();
	void RemoveBook();


	std::vector<Book> GetAllBooks() const;
};
