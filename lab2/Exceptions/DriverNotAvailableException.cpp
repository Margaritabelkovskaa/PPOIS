#include "DriverNotAvailableException.h"

DriverNotAvailableException::DriverNotAvailableException()
    : TransportException("Driver is not available") {}
