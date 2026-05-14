#include "../include/openlibrary.h"
#include <curl/curl.h>
#include <curl/easy.h>
#include <iostream>

size_t OpenLibClient::WriteCallBack(void *contents, size_t size, size_t nmemb,
                                    std::string *output) {
  size_t totalSize = size * nmemb;
  output->append(static_cast<char *>(contents), totalSize);

  return totalSize;
};

std::string OpenLibClient::PerformGetRequest(const std::string &url) {
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
      std::cout << curl_easy_strerror(result);
    }

  } else {
    std::cout << "Curl handle was not initialized." << std::endl;
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
