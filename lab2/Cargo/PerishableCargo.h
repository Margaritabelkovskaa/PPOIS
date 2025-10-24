#ifndef PERISHABLECARGO_H
#define PERISHABLECARGO_H

#include "Cargo.h"
#include <string>

class PerishableCargo : public Cargo {
private:
    double requiredTemperature;       // ��������� �����������
    double temperatureTolerance;      // ������ �����������
    std::string expiryDate;           // ���� ��������
    std::string harvestDate;          // ���� �����/������������
    double humidityLevel;             // ������� ���������
    bool requiresVentilation;         // ��������� ����������
    std::string storageInstructions;  // ���������� �� ��������
    int maxTransportTime;             // ����. ����� ��������� (����)
    std::string qualityControlChecklist; // ���-���� �������� ��������
    bool ethyleneSensitive;           // ���������������� � �������

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

    // �������
    double getRequiredTemperature() const { return requiredTemperature; }
    std::string getExpiryDate() const { return expiryDate; }
    int getMaxTransportTime() const { return maxTransportTime; }
};

#endif