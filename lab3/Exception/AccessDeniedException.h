#ifndef ACCESSDENIEDEXCEPTION_H
#define ACCESSDENIEDEXCEPTION_H

#include "LibraryException.h"
#include <string>

class AccessDeniedException : public LibraryException {
public:
    explicit AccessDeniedException(const std::string& role);
};

#endif
