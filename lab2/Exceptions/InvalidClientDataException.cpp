#include "InvalidClientDataException.h"

InvalidClientDataException::InvalidClientDataException(const std::string& field)
    : TransportException("Invalid client data in field: " + field) {}
