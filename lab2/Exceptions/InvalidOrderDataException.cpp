#include "InvalidOrderDataException.h"

InvalidOrderDataException::InvalidOrderDataException(const std::string& field)
    : TransportException("Invalid order data in field: " + field) {}
