# LibreShelf

A command-line application for managing a personal library.

## Description

LibreShelf lets you keep a digital record of your books locally. You can add, list, filter, search, edit, and remove books from your collection. It also includes an Open Library lookup so you can search for books by title, author, or ISBN without typing the details yourself.

## Dependencies

- A C++ compiler with C++23 support (g++ 13+)
- `libcurl` development headers
- `make`

On Arch: `sudo pacman -S curl`
On Debian/Ubuntu: `sudo apt install libcurl4-openssl-dev`

The `nlohmann/json` library is included as a single header in the `include/` directory, so no separate install is needed.

## Build and Run

```bash
make
./libreshelf
```

To clean up build artifacts:

```bash
make clean
```

## Usage

The menu presents the following options:

1. List all books
2. Filter by trait (author, genre, status, or rating)
3. Search for a book by title
4. Add a book
5. Edit a book
6. Edit a single field of a book
7. Remove a book
8. Search Open Library (by title, author, or ISBN)
0. Quit

Library data is stored in `data/books.csv`.
