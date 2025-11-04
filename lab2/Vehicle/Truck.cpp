#include "Truck.h"

Truck::Truck(const std::string& plate, const std::string& model,
    double capacity, double trailerCap, bool refrigeration, int axles)
    : Vehicle(plate, model, capacity), trailerCapacity(trailerCap),
    hasRefrigeration(refrigeration), axleCount(axles) {
}

double Truck::getTotalCapacity() const {
    return getCapacity() + trailerCapacity;
}

void Truck::attachTrailer() {
    // Логика присоединения прицепа
}

void Truck::detachTrailer() {
    // Логика отсоединения прицепа
}