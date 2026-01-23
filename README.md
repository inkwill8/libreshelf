# LibreShelf

A simple command-line application for managing a personal library.

## Description

LibreShelf allows you to keep a digital record of your books. You can add new books, view your entire collection, find specific books, and remove books from your library. All data is handled locally on your machine.

## How to Compile and Run

This project is written in C++. You will need a C++ compiler (like g++) to build and run it.

1.  **Navigate to the source directory:**
    ```bash
    cd src
    ```

2.  **Compile the project:**
    ```bash
    g++ main.cpp book.cpp menu.cpp helper.cpp -o libreshelf
    ```

3.  **Run the application:**
    ```bash
    ./libreshelf
    ```

## Usage

Once the application is running, you will be presented with a menu of options:

*   **Add a new book:** Add a book to your collection by providing a title and author.
*   **Print library:** Display a list of all the books currently in your library.
*   **Find a book:** Search for a specific book in your library.
*   **Delete a book:** Remove a book from your library.
