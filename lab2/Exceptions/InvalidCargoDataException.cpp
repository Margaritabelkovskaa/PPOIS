#include "InvalidCargoDataException.h"

InvalidCargoDataException::InvalidCargoDataException(const std::string& field)
    : TransportException("Invalid cargo data in field: " + field) {}
