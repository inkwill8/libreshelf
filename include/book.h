#pragma once
#include "types.h"
#include <string>
#include <ostream>

class Book {
private:
	std::string _title;
	std::string _author;
	std::string _isbn;
	Genre _genre;
	Status _status;
	float _rating;

public:
	Book(std::string title, std::string author, std::string isbn, Genre genre, Status status, float rating);
	friend std::ostream& operator<<(std::ostream& os, const Book& book);

};
