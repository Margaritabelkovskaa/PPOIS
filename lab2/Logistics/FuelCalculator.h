#ifndef FUELCALCULATOR_H
#define FUELCALCULATOR_H

class FuelCalculator {
private:
    double baseFuelConsumption; 
    double currentFuelPrice;
    double vehicleLoadFactor;

public:
    FuelCalculator(double consumption, double fuelPrice);

    double calculateFuelCost(double distance) const;
    double calculateOptimalSpeed(double distance) const;
    void updateFuelPrice(double newPrice);

    double getCurrentFuelPrice() const { return currentFuelPrice; }
};

#endif
