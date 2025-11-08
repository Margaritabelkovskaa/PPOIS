
#include "PerishableCargo.h"

PerishableCargo::PerishableCargo(const std::string& desc, double weight,
    double reqTemp, const std::string& expiry, int maxTransport)
    : Cargo(desc, weight), requiredTemperature(reqTemp),
      expiryDate(expiry), maxTransportTime(maxTransport),
      requiresRefrigeration(reqTemp < 10.0) {
}

bool PerishableCargo::isExpired() const {
    // Простая проверка - всегда свежий для примера
    return false;
}

bool PerishableCargo::validateTemperature(double currentTemp) const {
    return requiresRefrigeration ? currentTemp <= requiredTemperature : true;
}

bool PerishableCargo::needsRefrigeration() const {
    return requiresRefrigeration;
}

std::string PerishableCargo::getStorageInfo() const {
    return "Temp: " + std::to_string(requiredTemperature) + 
           "C, Expiry: " + expiryDate;
}
