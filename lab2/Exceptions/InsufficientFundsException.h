#ifndef INSUFFICIENTFUNDSEXCEPTION_H
#define INSUFFICIENTFUNDSEXCEPTION_H

#include "TransportException.h"

class InsufficientFundsException : public TransportException {
public:
    InsufficientFundsException();
};

#endif
