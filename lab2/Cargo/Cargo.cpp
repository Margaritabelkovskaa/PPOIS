#include "Cargo.h"

Cargo::Cargo(const std::string& desc, double weight, double volume,
    const std::string& type, bool fragile, bool refrigeration)
    : description(desc), weight(weight), volume(volume), type(type),
    isFragile(fragile), requiresRefrigeration(refrigeration) {
}

double Cargo::calculateShippingCost(double baseRate) const {
    double cost = baseRate * weight;
    if (isFragile) cost *= 1.5;
    if (requiresRefrigeration) cost *= 2.0;
    return cost;
}

bool Cargo::requiresSpecialHandling() const {
    return isFragile || requiresRefrigeration;
}