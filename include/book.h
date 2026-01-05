#pragma once
#include "types.h"
#include <string>

class Book {
private:
	std::string _title;
	std::string _author;
	std::string _isbn;
	Genre _genre;
	Status _status;
	int _rating;

public:
	Book(std::string title, std::string author, std::string isbn, Genre genre, Status status, int rating);

};
