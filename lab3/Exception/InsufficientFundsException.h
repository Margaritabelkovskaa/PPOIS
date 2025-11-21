#ifndef INSUFFICIENTFUNDSEXCEPTION_H
#define INSUFFICIENTFUNDSEXCEPTION_H

#include "LibraryException.h"

class InsufficientFundsException : public LibraryException {
public:
    explicit InsufficientFundsException(double amount);
};

#endif
