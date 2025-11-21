#ifndef BOOKNOTFOUNDEXCEPTION_H
#define BOOKNOTFOUNDEXCEPTION_H

#include "LibraryException.h"
#include <string>

class BookNotFoundException : public LibraryException {
public:
    explicit BookNotFoundException(const std::string& isbn);
};

#endif
