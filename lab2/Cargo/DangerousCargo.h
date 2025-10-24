#ifndef DANGEROUSGOODS_H
#define DANGEROUSGOODS_H

#include "Cargo.h"
#include <vector>
#include <string>

class DangerousGoods : public Cargo {
private:
    std::string hazardClass;          // 1-9 ����� ���������
    std::string unNumber;             // UN �����
    std::string packingGroup;         // I, II, III
    std::string properShippingName;   // ������������ �� ���������
    bool requiresSpecialPermit;       // ��������� ��������������
    std::string emergencyContact;     // ������� ��� ��
    double maxAllowedTemperature;     // ����. �����������
    bool incompatibleWithWater;       // ����������� � �����
    std::vector<std::string> requiredSafetyEquipment; // ����������� ������������

public:
    DangerousGoods(const std::string& desc, double weight, double volume,
        const std::string& type, bool fragile, bool refrigeration,
        const std::string& hazardClass, const std::string& unNumber,
        const std::string& packingGroup, const std::string& shippingName,
        bool specialPermit, const std::string& emergencyContact,
        double maxTemp, bool waterIncompatible);

    // ����������� ������ ��� ������� ������
    bool validateTransportDocuments() const;
    double calculateRiskFactor() const;
    bool checkCompatibilityWithOtherCargo(const Cargo* other) const;
    std::string generateEmergencyProcedures() const;
    bool requiresSpecialVehicle() const;
    double calculateAdditionalInsurance() const;
    void addSafetyEquipment(const std::string& equipment);
    bool isHighlyDangerous() const;

    // �������
    std::string getHazardClass() const { return hazardClass; }
    std::string getUnNumber() const { return unNumber; }
    bool getRequiresSpecialPermit() const { return requiresSpecialPermit; }
};

#endif