#ifndef MACHINE_H
#define MACHINE_H

#include "Vehicle.h"
#include <string>

class Machine : public Vehicle {
private:
    std::string carType;
    int passengerSeats;
    std::string comfortLevel;
    bool hasAirConditioning;
    double fuelConsumption;

public:
    Machine(const std::string& plate, const std::string& model, double capacity,
        const std::string& type, int seats, const std::string& comfort, bool ac, double consumption);

    bool canCarryPassengers(int passengerCount) const;
    double calculateTripCost(double distance, double fuelPrice) const;
    bool isComfortForBusiness() const;
    void serviceCar();

    std::string getCarType() const { return carType; }
    int getPassengerSeats() const { return passengerSeats; }
    std::string getComfortLevel() const { return comfortLevel; }
};

#endif