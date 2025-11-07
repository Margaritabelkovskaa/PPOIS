#include "FuelCalculator.h"
#include <algorithm>

FuelCalculator::FuelCalculator(double consumption, double fuelPrice)
    : baseFuelConsumption(consumption), currentFuelPrice(fuelPrice), 
      vehicleLoadFactor(DEFAULT_LOAD_FACTOR) {
}

double FuelCalculator::calculateFuelCost(double distance) const {
    double fuelNeeded = (baseFuelConsumption * distance / 100.0) * vehicleLoadFactor;
    return fuelNeeded * currentFuelPrice;
}

double FuelCalculator::calculateOptimalSpeed(double distance) const {
    return std::min(MAX_OPTIMAL_SPEED, BASE_SPEED + distance * SPEED_CALCULATION_FACTOR);
}

void FuelCalculator::updateFuelPrice(double newPrice) {
    currentFuelPrice = newPrice;
}
