#include "book.h"

Book::Book(std::string title, std::string author, std::string isbn, Genre genre, Status status, Rating rating) : 
	title(_title), author(_author), isbn(_isbn), genre(_genre), status(_status), rating(_rating)
{ }
