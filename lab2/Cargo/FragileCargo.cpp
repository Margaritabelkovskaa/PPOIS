#include "FragileCargo.h"

FragileCargo::FragileCargo(const std::string& desc, double weight,
    double fragilityLevel, double maxGForce, const std::string& instructions)
    : Cargo(desc, weight), fragilityLevel(fragilityLevel),
      maxAllowedGForce(maxGForce), handlingInstructions(instructions),
      requiresSpecialPackaging(fragilityLevel > 5.0) {
}

double FragileCargo::calculateFragilityFactor() const {
    return fragilityLevel * (1.0 / maxAllowedGForce);
}

bool FragileCargo::validatePackaging() const {
    return requiresSpecialPackaging || !handlingInstructions.empty();
}

double FragileCargo::calculateSurcharge(double baseRate) const {
    return baseRate * (1.0 + fragilityLevel * 0.1);
}

std::string FragileCargo::getHandlingInfo() const {
    return "Fragility: " + std::to_string(fragilityLevel) + 
           ", Max G: " + std::to_string(maxAllowedGForce) +
           ", Instructions: " + handlingInstructions;
}
