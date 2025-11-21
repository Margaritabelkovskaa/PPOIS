#include "BookNotFoundException.h"

BookNotFoundException::BookNotFoundException(const std::string& isbn)
    : LibraryException("Book not found: " + isbn) {
}
