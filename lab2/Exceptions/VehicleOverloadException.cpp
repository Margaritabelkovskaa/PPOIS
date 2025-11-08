#include "VehicleOverloadException.h"

VehicleOverloadException::VehicleOverloadException(double load, double capacity)
    : TransportException("Vehicle overload: " + std::to_string(load) + 
                        " kg exceeds capacity " + std::to_string(capacity) + " kg") {}
