#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include "GPSPosition.h"

class Driver;
class GPSPosition;

class Vehicle {
private:
    std::string licensePlate;
    std::string model;
    double capacity;
    double currentLoad;
    double fuelLevel;
    Driver* currentDriver;
    GPSPosition* currentLocation;
    bool isInUse;

public:
    Vehicle(const std::string& plate, const std::string& model, double capacity);
    ~Vehicle();

    bool loadCargo(double weight);
    void unloadCargo();
    void refuel(double amount);
    void updateLocation(GPSPosition* location);
    bool canCarry(double weight) const;

    std::string getLicensePlate() const { return licensePlate; }
    double getCapacity() const { return capacity; }
    bool getIsInUse() const { return isInUse; }
};

#endif
