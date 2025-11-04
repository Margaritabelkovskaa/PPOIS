#include "Van.h"

Van::Van(const std::string& plate, const std::string& model,
    double capacity, int maxPackages, bool electric)
    : Vehicle(plate, model, capacity), maxPackages(maxPackages),
    isElectric(electric), batteryLevel(100.0) {
}

void Van::chargeBattery(double hours) {
    if (isElectric) {
        batteryLevel += hours * 10; // 10% β χΰρ
        if (batteryLevel > 100) batteryLevel = 100;
    }
}

double Van::getRemainingRange() const {
    return isElectric ? batteryLevel * 5 : getCapacity() * 0.1; // κμ
}

bool Van::canDeliverPackages(int packageCount) const {
    return packageCount <= maxPackages;
}