#include "../include/bookmatcher.h"

std::string BookMatcher::Normalize(std::string title) {
  title = Helper::ToLowercase(title);
  title = Helper::RemoveLeadingArticle(title);
  title = Helper::RemoveChars(title, ".,():-?!;\"'");
  title = Helper::RemoveChars(title, " ");

  return title;
};

bool BookMatcher::IsSameBook(std::string bookA, std::string bookB) {
  // Compare the two normalized results
  return Normalize(bookA) == Normalize(bookB);
};
