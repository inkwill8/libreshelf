#include "../include/openlibrary.h"
#include <curl/curl.h>
#include <curl/easy.h>
#include <iostream>

using json = nlohmann::json;

size_t OpenLibClient::WriteCallBack(void *contents, size_t size, size_t nmemb,
                                    std::string *output) {
  size_t totalSize = size * nmemb;
  output->append(static_cast<char *>(contents), totalSize);

  return totalSize;
};

std::optional<std::string>
OpenLibClient::PerformGetRequest(const std::string &url) {
  std::string responseBuffer;
  CURL *curl = curl_easy_init();

  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallBack);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBuffer);

    CURLcode result = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    if (result != CURLE_OK) {
      std::cerr << "Request failed: " << curl_easy_strerror(result) << "\n";
      return std::nullopt;
    }

  } else {
    std::cerr << "Curl handle was not initialized.\n";
    return std::nullopt;
  }

  return responseBuffer;
};

std::string OpenLibClient::UrlEncode(const std::string &input) {
  CURL *curl = curl_easy_init();

  char *encoded = curl_easy_escape(curl, input.c_str(), input.length());
  std::string result = encoded;
  curl_free(encoded);
  curl_easy_cleanup(curl);

  return result;
};

std::optional<nlohmann::json>
OpenLibClient::ParseJSON(std::optional<std::string> &response) {

  if (!response.has_value()) {
    return std::nullopt; // network failed
  }

  // Parse the JSON from the request
  json parsed = json::parse(*response, nullptr, false);

  if (parsed.is_discarded()) { // parsing error
    std::cerr << "Failed to parse response.\n";
    return std::nullopt;
  }

  return parsed;
};

std::vector<Book> OpenLibClient::BuildBooks(const nlohmann::json &parsed) {

  std::vector<Book> results;

  // no docs field but request went through, return empty vector
  if (!parsed.contains("docs") || !parsed["docs"].is_array()) {
    return results;
  }

  for (const auto &doc : parsed["docs"]) {
    Book book;

    if (doc.contains("title")) {
      book.SetTitle(doc["title"]);
    }
    if (doc.contains("author_name") && !doc["author_name"].empty()) {
      book.SetAuthor(doc["author_name"][0]);
    }
    if (doc.contains("isbn") && !doc["isbn"].empty()) {
      book.SetIsbn(doc["isbn"][0]);
    }

    results.push_back(book);
  }

  return results;
};

std::optional<std::vector<Book>>
OpenLibClient::SearchByTitle(const std::string &title) {
  std::string url =
      "https://openlibrary.org/search.json?title=" + UrlEncode(title) +
      "&fields=title,author_name,isbn,first_publish_year,edition_count" +
      "&limit=20";

  // Hit the OpenLibrary API endpoint
  std::optional<std::string> response = PerformGetRequest(url);

  // Use nlohmann::json to parse the raw response from OpenLibrary
  // This checks if the network request went thru and if the JSON was parsed
  // properly
  std::optional<json> parsed = ParseJSON(response);
  if (parsed == std::nullopt) {
    return std::nullopt;
  }

  // If everything checks out, we build a Books vector based on the results
  std::vector<Book> results = BuildBooks(parsed);

  return results;
};

std::optional<std::vector<Book>>
OpenLibClient::SearchByAuthor(const std::string &author) {

  std::string url =
      "https://openlibrary.org/search.json?author=" + UrlEncode(author) +
      "&fields=title,author_name,isbn,first_publish_year,edition_count" +
      "&limit=20";

  std::optional<std::string> response = PerformGetRequest(url);

  std::optional<json> parsed = ParseJSON(response);
  if (parsed == std::nullopt) {
    return std::nullopt;
  }

  std::vector<Book> results = BuildBooks(parsed);

  return results;
};
