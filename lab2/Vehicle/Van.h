#ifndef VAN_H
#define VAN_H

#include "Vehicle.h"

class Van : public Vehicle {
private:
    int maxPackages;
    bool isElectric;
    double batteryLevel;

public:
    Van(const std::string& plate, const std::string& model,
        double capacity, int maxPackages, bool electric);

    void chargeBattery(double hours);
    double getRemainingRange() const;
    bool canDeliverPackages(int packageCount) const;

    int getMaxPackages() const { return maxPackages; }
    bool getIsElectric() const { return isElectric; }
};

#endif#pragma once
