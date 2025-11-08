#ifndef DRIVERNOTAVAILABLEEXCEPTION_H
#define DRIVERNOTAVAILABLEEXCEPTION_H

#include "TransportException.h"

class DriverNotAvailableException : public TransportException {
public:
    DriverNotAvailableException();
};

#endif
