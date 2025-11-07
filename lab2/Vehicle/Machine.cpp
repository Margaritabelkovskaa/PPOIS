#include "Machine.h"

Machine::Machine(const std::string& plate, const std::string& model, double capacity,
    const std::string& type, int seats, const std::string& comfort, bool ac, double consumption)
    : Vehicle(plate, model, capacity), carType(type), passengerSeats(seats),
    comfortLevel(comfort), hasAirConditioning(ac), fuelConsumption(consumption) {
}

bool Machine::canCarryPassengers(int passengerCount) const {
    return passengerCount <= passengerSeats;
}

double Machine::calculateTripCost(double distance, double fuelPrice) const {
    double fuelUsed = (distance / 100.0) * fuelConsumption;
    return fuelUsed * fuelPrice;
}

bool Machine::isComfortForBusiness() const {
    return comfortLevel == "business" || comfortLevel == "comfort";
}

void Machine::serviceCar() {
    refuel(50.0);
}