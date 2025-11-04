#include "Vehicle.h"
#include "Driver.h"
#include "GPSPosition.h"

Vehicle::Vehicle(const std::string& plate, const std::string& model, double capacity)
    : licensePlate(plate), model(model), capacity(capacity), currentLoad(0),
    fuelLevel(0), currentDriver(nullptr), currentLocation(nullptr), isInUse(false) {
}

Vehicle::~Vehicle() {
    delete currentLocation;
}

bool Vehicle::loadCargo(double weight) {
    if (currentLoad + weight <= capacity) {
        currentLoad += weight;
        return true;
    }
    return false;
}

void Vehicle::unloadCargo() {
    currentLoad = 0;
}

void Vehicle::refuel(double amount) {
    fuelLevel += amount;
}

void Vehicle::updateLocation(GPSPosition* location) {
    delete currentLocation;
    currentLocation = location;
}

bool Vehicle::canCarry(double weight) const {
    return currentLoad + weight <= capacity;
}