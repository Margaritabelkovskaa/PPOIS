#ifndef PERISHABLECARGO_H
#define PERISHABLECARGO_H

#include "Cargo.h"
#include <string>

class PerishableCargo : public Cargo {
private:
    double requiredTemperature;       // Требуемая температура
    double temperatureTolerance;      // Допуск температуры
    std::string expiryDate;           // Срок годности
    std::string harvestDate;          // Дата сбора/производства
    double humidityLevel;             // Уровень влажности
    bool requiresVentilation;         // Требуется вентиляция
    std::string storageInstructions;  // Инструкции по хранению
    int maxTransportTime;             // Макс. время перевозки (часы)
    std::string qualityControlChecklist; // Чек-лист контроля качества
    bool ethyleneSensitive;           // Чувствительность к этилену

public:
    PerishableCargo(const std::string& desc, double weight, double volume,
        const std::string& type, bool fragile,
        double reqTemp, double tempTolerance, const std::string& expiry,
        const std::string& harvest, double humidity, bool ventilation,
        int maxTransport, bool ethyleneSensitive);

    bool isStillFresh() const;
    double calculateRemainingShelfLife() const;
    bool validateTemperatureCompliance(double currentTemp) const;
    void updateQualityStatus(const std::string& status);
    double calculateQualityPenalty(double deviation) const;
    bool requiresRefrigeration() const;
    bool isExpired() const;
    std::string getQualityStatus() const;

    // Геттеры
    double getRequiredTemperature() const { return requiredTemperature; }
    std::string getExpiryDate() const { return expiryDate; }
    int getMaxTransportTime() const { return maxTransportTime; }
};

#endif