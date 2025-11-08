#ifndef INVALIDCLIENTDATAEXCEPTION_H
#define INVALIDCLIENTDATAEXCEPTION_H

#include "TransportException.h"

class InvalidClientDataException : public TransportException {
public:
    explicit InvalidClientDataException(const std::string& field);
};

#endif
