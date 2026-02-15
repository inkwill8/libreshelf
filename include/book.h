#pragma once
#include "types.h"
#include <ostream>
#include <string>

class Book {
private:
  std::string _title;
  std::string _author;
  std::string _isbn;
  Genre _genre;
  Status _status;
  float _rating;

public:
  Book(std::string title, std::string author, std::string isbn, Genre genre,
       Status status, float rating);
  friend std::ostream &operator<<(std::ostream &os, const Book &book);

  // Getters
  std::string GetTitle() const;
  std::string GetAuthor() const;
  std::string GetIsbn() const;
  Genre GetGenre() const;
  Status GetStatus() const;
  float GetRating() const;

  std::string GetStrGenre() const;
  std::string GetStrStatus() const;

  // Setters
  void SetTitle(std::string title);
  void SetAuthor(std::string author);
  void SetIsbn(std::string isbn);
  void SetGenre(Genre genre);
  void SetStatus(Status status);
  void SetRating(float rating);
};
