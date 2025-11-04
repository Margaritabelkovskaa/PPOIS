#include "Trailer.h"
#include "Truck.h"

Trailer::Trailer(const std::string& id, const std::string& type, double capacity,
    bool refrigeration, double length, double width, double height)
    : trailerId(id), type(type), capacity(capacity), currentLoad(0),
    isAttached(false), attachedToTruck(nullptr), hasRefrigeration(refrigeration),
    length(length), width(width), height(height) {
}

void Trailer::attachToTruck(Truck* truck) {
    if (truck && !isAttached) {
        attachedToTruck = truck;
        isAttached = true;
    }
}

void Trailer::detachFromTruck() {
    attachedToTruck = nullptr;
    isAttached = false;
}

bool Trailer::loadCargo(double weight) {
    if (currentLoad + weight <= capacity) {
        currentLoad += weight;
        return true;
    }
    return false;
}

void Trailer::unloadCargo() {
    currentLoad = 0;
}

double Trailer::getAvailableCapacity() const {
    return capacity - currentLoad;
}

bool Trailer::requiresSpecialLicense() const {
    return capacity > 3500 || type == "refrigerated" || type == "hazardous";
}