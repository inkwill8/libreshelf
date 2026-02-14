#include "../include/book.h"
#include "../include/helper.h"

Book::Book(std::string title, std::string author, std::string isbn, Genre genre,
           Status status, float rating)
    : _title(title), _author(author), _isbn(isbn), _genre(genre),
      _status(status), _rating(rating) {}

std::ostream &operator<<(std::ostream &os, const Book &book) {
  os << book._title << " | " << book._author << " | " << "ISBN: " << book._isbn
     << " | " << Helper::GenreToStr(book._genre) << " | "
     << Helper::StatusToStr(book._status) << " | " << book._rating;

  return os;
};

// GETTERS
std::string Book::GetTitle() const { return _title; };
std::string Book::GetAuthor() const { return _author; };
std::string Book::GetIsbn() const { return _isbn; };
Genre Book::GetGenre() const { return _genre; };
Status Book::GetStatus() const { return _status; };
float Book::GetRating() const { return _rating; };

std::string Book::GetStrGenre() const {
  std::string genre = Helper::GenreToStr(_genre);
  return genre;
};

std::string Book::GetStrStatus() const {
  std::string status = Helper::StatusToStr(_status);
  return status;
};
