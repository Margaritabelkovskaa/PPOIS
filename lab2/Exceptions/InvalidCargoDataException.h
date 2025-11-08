#ifndef INVALIDCARGODATAEXCEPTION_H
#define INVALIDCARGODATAEXCEPTION_H

#include "TransportException.h"

class InvalidCargoDataException : public TransportException {
public:
    explicit InvalidCargoDataException(const std::string& field);
};

#endif
