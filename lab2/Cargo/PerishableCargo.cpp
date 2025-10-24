#include "PerishableCargo.h"
#include <ctime>
#include <sstream>
#include <iomanip>

PerishableCargo::PerishableCargo(const std::string& desc, double weight, double volume,
    const std::string& type, bool fragile,
    double reqTemp, double tempTolerance, const std::string& expiry,
    const std::string& harvest, double humidity, bool ventilation,
    int maxTransport, bool ethyleneSensitive)
    : Cargo(desc, weight, volume, type, fragile, reqTemp < 10.0), // Рефрижерация если требуется температура <10°C
    requiredTemperature(reqTemp), temperatureTolerance(tempTolerance),
    expiryDate(expiry), harvestDate(harvest), humidityLevel(humidity),
    requiresVentilation(ventilation), maxTransportTime(maxTransport),
    ethyleneSensitive(ethyleneSensitive) {
}

bool PerishableCargo::isStillFresh() const {
    return !isExpired();
}

double PerishableCargo::calculateRemainingShelfLife() const {
    // Упрощенный расчет оставшегося срока годности
    return 5.0; // дней
}

bool PerishableCargo::validateTemperatureCompliance(double currentTemp) const {
    double lowerLimit = requiredTemperature - temperatureTolerance;
    double upperLimit = requiredTemperature + temperatureTolerance;
    return currentTemp >= lowerLimit && currentTemp <= upperLimit;
}

void PerishableCargo::updateQualityStatus(const std::string& status) {
    qualityControlChecklist = status;
}

double PerishableCargo::calculateQualityPenalty(double deviation) const {
    double penaltyRate = 0.0;

    if (std::abs(deviation) > temperatureTolerance * 2) {
        penaltyRate = 0.5; // 50% штраф за серьезное отклонение
    }
    else if (std::abs(deviation) > temperatureTolerance) {
        penaltyRate = 0.2; // 20% штраф за умеренное отклонение
    }

    return Cargo::calculateShippingCost(1.0) * penaltyRate;
}

bool PerishableCargo::requiresRefrigeration() const {
    return requiredTemperature < 15.0; // Все что ниже 15°C требует охлаждения
}

bool PerishableCargo::isExpired() const {
    // Упрощенная проверка (в реальности нужно парсить дату)
    return expiryDate < "2024-01-01"; // Пример
}

std::string PerishableCargo::getQualityStatus() const {
    if (isExpired()) return "EXPIRED";
    return "FRESH";
}