#ifndef INVALIDORDERDATAEXCEPTION_H
#define INVALIDORDERDATAEXCEPTION_H

#include "TransportException.h"

class InvalidOrderDataException : public TransportException {
public:
    explicit InvalidOrderDataException(const std::string& field);
};

#endif
