#include "RouteException.h"

RouteException::RouteException(const std::string& reason)
    : TransportException("Route error: " + reason) {}
