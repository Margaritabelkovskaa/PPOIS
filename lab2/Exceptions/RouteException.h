#ifndef ROUTEEXCEPTION_H
#define ROUTEEXCEPTION_H

#include "TransportException.h"

class RouteException : public TransportException {
public:
    explicit RouteException(const std::string& reason);
};

#endif
