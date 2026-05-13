#include "../include/menu.h"
#include <curl/curl.h>
#include <curl/urlapi.h>
#include <iostream>

int main() {

  CURLcode result = curl_global_init(CURL_GLOBAL_ALL);

  if (result == CURLE_OK) {

    std::cout << "##################" << std::endl;
    std::cout << "### LibreShelf ###" << std::endl;
    std::cout << "##################" << std::endl;

    Menu mainMenu;
    mainMenu.DisplayMainMenu();

    curl_global_cleanup();

  } else {
    std::cout << curl_easy_strerror(result);
  }

  return 0;
};
