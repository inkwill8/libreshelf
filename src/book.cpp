#include "../include/book.h"

Book::Book(std::string title, std::string author, std::string isbn, Genre genre, Status status, float rating) : 
	_title(title), _author(author), _isbn(isbn), _genre(genre), _status(status), _rating(rating)
{ }
