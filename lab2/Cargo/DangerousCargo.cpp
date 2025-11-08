#include "DangerousCargo.h"

DangerousCargo::DangerousCargo(const std::string& desc, double weight,
    const std::string& hazardClass, const std::string& unNumber)
    : Cargo(desc, weight), hazardClass(hazardClass), unNumber(unNumber),
      requiresSpecialPermit(false), emergencyContact("") {
}

bool DangerousCargo::validateDocuments() const {
    return !unNumber.empty() && !hazardClass.empty();
}

double DangerousCargo::calculateRisk() const {
    if (hazardClass == "1" || hazardClass == "7") return 5.0;
    if (hazardClass == "6" || hazardClass == "8") return 4.0;
    return 2.0;
}

bool DangerousCargo::needsSpecialVehicle() const {
    return hazardClass == "1" || hazardClass == "7" || requiresSpecialPermit;
}

std::string DangerousCargo::getEmergencyInfo() const {
    return "Emergency: " + emergencyContact + " UN: " + unNumber;
}
