#include "../include/menu.h"
#include <iostream>

int main() {
  std::cout << "##################" << std::endl;
  std::cout << "### LibreShelf ###" << std::endl;
  std::cout << "##################" << std::endl;

  Menu mainMenu;
  mainMenu.DisplayMainMenu();

  return 0;
};
