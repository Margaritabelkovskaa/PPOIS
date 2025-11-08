#include "CargoOverweightException.h"

CargoOverweightException::CargoOverweightException(double weight, double maxWeight)
    : TransportException("Cargo overweight: " + std::to_string(weight) + 
                        " kg exceeds maximum " + std::to_string(maxWeight) + " kg") {}
