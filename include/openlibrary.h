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
  std::optional<std::string> PerformGetRequest(const std::string &url);
  std::string UrlEncode(const std::string &input);

  // Helper methods to parse JSON response and build native LibreShelf book objs
  std::optional<nlohmann::json> ParseJSON(std::optional<std::string> &response);
  std::vector<Book> BuildBooks(const nlohmann::json &parsed);

public:
  std::optional<std::vector<Book>> SearchByTitle(const std::string &title);
  std::optional<std::vector<Book>> SearchByAuthor(const std::string &author);
  std::optional<std::vector<Book>> SearchByIsbn(const std::string &isbn);

  // In case we want to include series search functionality and parsing of
  // OpenLibrary edition info
  std::vector<Book> SearchBySeries(const std::string &series);
};
