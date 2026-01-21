#include "../include/book.h"
#include "../include/helper.h"

Book::Book(std::string title, std::string author, std::string isbn, Genre genre, Status status, float rating) : 
	_title(title), _author(author), _isbn(isbn), _genre(genre), _status(status), _rating(rating)
{ }

std::ostream& operator<<(std::ostream& os, const Book& book) {
	os << book._title << " by " << book._author << " " << "ISBN: " << book._isbn <<
	" | " << Helper::GenreToStr(book._genre) << " | " << Helper::StatusToStr(book._status) << 
	" | " << book._rating;

	return os;
};
