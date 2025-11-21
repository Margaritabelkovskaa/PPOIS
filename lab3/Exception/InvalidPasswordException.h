#ifndef INVALIDPASSWORDEXCEPTION_H
#define INVALIDPASSWORDEXCEPTION_H

#include "LibraryException.h"

class InvalidPasswordException : public LibraryException {
public:
    InvalidPasswordException();
};

#endif
