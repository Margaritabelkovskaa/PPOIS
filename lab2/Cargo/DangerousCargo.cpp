#include "DangerousCargo.h"
#include <cmath>

DangerousGoods::DangerousGoods(const std::string& desc, double weight, double volume,
    const std::string& type, bool fragile, bool refrigeration,
    const std::string& hazardClass, const std::string& unNumber,
    const std::string& packingGroup, const std::string& shippingName,
    bool specialPermit, const std::string& emergencyContact,
    double maxTemp, bool waterIncompatible)
    : Cargo(desc, weight, volume, type, fragile, refrigeration),
    hazardClass(hazardClass), unNumber(unNumber), packingGroup(packingGroup),
    properShippingName(shippingName), requiresSpecialPermit(specialPermit),
    emergencyContact(emergencyContact), maxAllowedTemperature(maxTemp),
    incompatibleWithWater(waterIncompatible) {
}

bool DangerousGoods::validateTransportDocuments() const {
    return !unNumber.empty() && !properShippingName.empty() &&
        (!requiresSpecialPermit || emergencyContact != "");
}

double DangerousGoods::calculateRiskFactor() const {
    double baseRisk = 1.0;

    // Класс опасности влияет на риск
    if (hazardClass == "1" || hazardClass == "7") baseRisk = 5.0;
    else if (hazardClass == "2" || hazardClass == "3") baseRisk = 3.0;
    else if (hazardClass == "6" || hazardClass == "8") baseRisk = 4.0;

    // Группа упаковки влияет на риск
    if (packingGroup == "I") baseRisk *= 1.5;
    else if (packingGroup == "II") baseRisk *= 1.2;

    return baseRisk * getWeight() / 1000.0;
}

bool DangerousGoods::checkCompatibilityWithOtherCargo(const Cargo* other) const {
    if (!other) return true;

    // Несовместимость с водой
    if (incompatibleWithWater && other->getDescription().find("liquid") != std::string::npos) {
        return false;
    }

    return true;
}

std::string DangerousGoods::generateEmergencyProcedures() const {
    std::string procedures = "Emergency procedures for " + properShippingName + " (UN " + unNumber + "):\n";

    if (incompatibleWithWater) {
        procedures += "- DO NOT use water for fire fighting\n";
        procedures += "- Use dry chemical or CO2 extinguishers\n";
    }

    if (hazardClass == "3") {
        procedures += "- Keep away from ignition sources\n";
        procedures += "- Evacuate area in case of leak\n";
    }

    procedures += "- Emergency contact: " + emergencyContact + "\n";

    return procedures;
}

bool DangerousGoods::requiresSpecialVehicle() const {
    return hazardClass == "1" || hazardClass == "7" || requiresSpecialPermit;
}

double DangerousGoods::calculateAdditionalInsurance() const {
    double baseCost = Cargo::calculateShippingCost(1.0);
    return baseCost * calculateRiskFactor() * 0.05;
}

void DangerousGoods::addSafetyEquipment(const std::string& equipment) {
    requiredSafetyEquipment.push_back(equipment);
}

bool DangerousGoods::isHighlyDangerous() const {
    return hazardClass == "1" || hazardClass == "6.1" || hazardClass == "7" || packingGroup == "I";
}