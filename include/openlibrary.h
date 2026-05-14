#pragma once
#include "book.h"
#include "json.hpp"
#include <curl/curl.h>
#include <string>

class OpenLibClient {

private:
  // Helper method to perform the curl get request and return the raw string
  std::string PerformGetRequest(const std::string &url);

public:
  std::vector<Book> SearchByTitle(const std::string &title);
  std::vector<Book> SearchByIsbn(const std::string &isbn);
  std::vector<Book> SearchByAuthor(const std::string &isbn);

  // In case we want to include series search functionality and parsing of
  // OpenLibrary edition info
};
