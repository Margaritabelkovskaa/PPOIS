#ifndef VEHICLEOVERLOADEXCEPTION_H
#define VEHICLEOVERLOADEXCEPTION_H

#include "TransportException.h"

class VehicleOverloadException : public TransportException {
public:
    VehicleOverloadException(double load, double capacity);
};

#endif
