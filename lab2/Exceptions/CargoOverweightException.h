#ifndef CARGOOVERWEIGHTEXCEPTION_H
#define CARGOOVERWEIGHTEXCEPTION_H

#include "TransportException.h"

class CargoOverweightException : public TransportException {
public:
    CargoOverweightException(double weight, double maxWeight);
};

#endif
