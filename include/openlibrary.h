#pragma once
#include "book.h"
#include "json.hpp"
#include <curl/curl.h>
#include <string>

class OpenLibClient {

private:
  // Helper methods to perform the curl get request and return the raw string
  static size_t WriteCallBack(void *contents, size_t size, size_t nmemb,
                              std::string *output);
  std::string PerformGetRequest(const std::string &url);
  std::string UrlEncode(const std::string &input);

public:
  std::optional<std::vector<Book>> SearchByTitle(const std::string &title);
  std::optional<std::vector<Book>> SearchByIsbn(const std::string &isbn);
  std::optional<std::vector<Book>> SearchByAuthor(const std::string &isbn);

  // In case we want to include series search functionality and parsing of
  // OpenLibrary edition info
  std::vector<Book> SearchBySeries(const std::string &series);
};
